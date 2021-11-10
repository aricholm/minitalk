/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_hexa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:42:30 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/07 17:45:15 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*add_hash(char *hexa, t_type type)
{
	char	*out;

	out = malloc((ft_strlen(hexa) + 3) * sizeof(char));
	if (!out)
		return (0);
	out[0] = '0';
	if (type == HEXA_UPPER)
		out[1] = 'X';
	else
		out[1] = 'x';
	ft_memcpy(&out[2], hexa, ft_strlen(hexa) + 1);
	free (hexa);
	return (out);
}

static char	*add_zero(char	*hexa, size_t zero)
{
	char	*out;
	size_t	i;

	i = 0;
	out = malloc((ft_strlen(hexa) + zero + 1) * sizeof(char));
	if (!out)
		return (0);
	while (i < zero)
		out[i++] = '0';
	ft_memcpy(&out[zero], hexa, ft_strlen(hexa));
	out[ft_strlen(hexa) + zero] = 0;
	free (hexa);
	return (out);
}

static unsigned long long	get_input(t_flags flag, va_list ap)
{
	unsigned long long	original;

	if (flag.lenght_modifier == NONE)
		original = (unsigned long long) va_arg(ap, unsigned int);
	if (flag.lenght_modifier == L)
		original = (unsigned long long) va_arg(ap, unsigned long);
	if (flag.lenght_modifier == LL)
		original = (unsigned long long) va_arg(ap, unsigned long long);
	if (flag.lenght_modifier == H)
		original = (unsigned long long) va_arg(ap, unsigned int);
	if (flag.lenght_modifier == HH)
		original = (unsigned long long) va_arg(ap, unsigned int);
	return (original);
}

size_t	use_hexa(t_flags flag, va_list ap)
{
	size_t				char_counter;
	char				*hexa;
	unsigned long long	original;
	size_t				len;

	char_counter = 0;
	original = get_input(flag, ap);
	hexa = itohex(original, flag.type, flag.lenght_modifier);
	len = ft_strlen(hexa);
	if (flag.precision > len)
		hexa = add_zero(hexa, flag.precision - len);
	if (original && flag.hash)
		hexa = add_hash(hexa, flag.type);
	if (!flag.dot && flag.zero && ft_strlen(hexa) < flag.width && !flag.minus)
		hexa = add_zero(hexa, flag.width - ft_strlen(hexa));
	len = ft_strlen(hexa);
	if (flag.width > len && !flag.minus)
		char_counter += write_spaces(flag.width - len);
	char_counter += write_string(hexa, len);
	if (flag.width > len && flag.minus)
		char_counter += write_spaces(flag.width - len);
	free (hexa);
	return (char_counter);
}
