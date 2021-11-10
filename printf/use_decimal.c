/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:33:20 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/09 12:48:19 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	is_negative(long long number)
{
	if (number < 0)
		return (TRUE);
	return (FALSE);
}

static long long	get_input(t_flags flag, va_list ap)
{
	long long	original;

	if (flag.lenght_modifier == NONE)
		original = (long long) va_arg(ap, int);
	if (flag.lenght_modifier == L)
		original = (long long) va_arg(ap, long);
	if (flag.lenght_modifier == LL)
		original = (long long) va_arg(ap, long long);
	if (flag.lenght_modifier == H)
		original = (short) va_arg(ap, int);
	if (flag.lenght_modifier == HH)
		original = (char) va_arg(ap, int);
	if (flag.zero && flag.minus)
		flag.zero = FALSE;
	if (flag.type == UNSIGNED)
		original = (unsigned) original;
	return (original);
}

static char	*add_before(char	*decimal, char c, size_t zero)
{
	char	*out;
	size_t	i;

	i = 0;
	out = malloc((ft_strlen(decimal) + zero + 1) * sizeof(char));
	if (!out)
		return (0);
	while (i < zero)
		out[i++] = c;
	ft_memcpy(&out[zero], decimal, ft_strlen(decimal));
	out[ft_strlen(decimal) + zero] = 0;
	free (decimal);
	return (out);
}

static char	*build_string(t_flags flag, long long original)
{
	char	*str;

	str = get_absolute_as_string(original);
	if (flag.precision > ft_strlen(str))
		str = add_before(str, '0', flag.precision - ft_strlen(str));
	if (ft_strlen(str) + is_negative(original) < flag.width)
	{
		if (flag.zero && !flag.dot && !flag.minus)
		{
			if (is_negative(original) || flag.space || flag.plus)
				str = add_before(str, '0', flag.width - ft_strlen(str) - 1);
			else
				str = add_before(str, '0', flag.width - ft_strlen(str));
		}
	}
	if (is_negative(original))
		str = add_before(str, '-', 1);
	else
	{
		if (flag.plus)
			str = add_before(str, '+', 1);
		else if (flag.space)
			str = add_before(str, ' ', 1);
	}
	return (str);
}

size_t	use_decimal(t_flags flag, va_list ap)
{
	size_t		char_counter;
	char		*string;
	long long	original;
	size_t		len;

	char_counter = 0;
	original = get_input(flag, ap);
	string = build_string(flag, original);
	if (flag.width > ft_strlen(string) && !flag.minus)
	{
		if (!flag.zero || flag.dot)
			string = add_before(string, ' ', flag.width - ft_strlen(string));
		else
			string = add_before(string, '0', flag.width - ft_strlen(string));
	}
	len = ft_strlen(string);
	char_counter += write_string(string, len);
	if (flag.width > len && flag.minus)
		char_counter += write_spaces(flag.width - len);
	free (string);
	return (char_counter);
}
