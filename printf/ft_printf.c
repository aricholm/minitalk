/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:41:58 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/09 12:56:31 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	The overall syntax of a conversion specification is:
**	%[flags][width][.precision][length modifier]conversion
*/

static size_t	simple_write(const char *input)
{
	write(1, input, 1);
	return (1);
}

static size_t	do_the_conversion(t_flags flag, va_list ap)
{
	if (flag.type == STRING)
		return (use_string(flag, ap));
	if (flag.type == CHAR)
		return (use_char(flag, ap));
	if (flag.type == HEXA || flag.type == HEXA_UPPER)
		return (use_hexa(flag, ap));
	if (flag.type == PERCENT)
	{
		write(1, "%", 1);
		return (1);
	}
	if (flag.type == POINTER)
	{
		flag.hash = TRUE;
		flag.lenght_modifier = LL;
		return (use_hexa(flag, ap));
	}
	if (flag.type == DECIMAL || flag.type == INTEGER)
		return (use_decimal(flag, ap));
	if (flag.type == UNSIGNED)
		return (use_decimal(flag, ap));
	return (INVALID);
}

static int	start_printf(const char *input, va_list ap)
{
	size_t	i;
	size_t	written_characters;
	t_flags	flag;

	written_characters = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			i++;
			init_flag(&flag);
			i += get_flags(&input[i], &flag);
			i += get_width_and_prec(&input[i], &flag, ap);
			i += get_modifier(&input[i], &flag);
			get_conversion(input[i], &flag);
			written_characters += do_the_conversion(flag, ap);
		}
		else
			written_characters += simple_write(&input[i]);
		i++;
	}
	return (written_characters);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	size_t	written_characters;

	va_start(ap, input);
	written_characters = start_printf(input, ap);
	va_end(ap);
	return (written_characters);
}
