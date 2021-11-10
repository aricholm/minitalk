/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:49:50 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/08 16:00:03 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

static size_t	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static size_t	get_precision(const char *input, t_flags *flag, va_list ap)
{
	size_t	i;
	int		tmp;

	i = 0;
	if (input[i] == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
			flag->dot = FALSE;
		else
			flag->precision = tmp;
		i++;
	}
	else
	{
		while (is_number(input[i]))
		{
			flag->precision *= 10;
			flag->precision += input[i] - '0';
			i++;
		}
	}
	return (i);
}

static size_t	get_width(const char *input, t_flags *flag, va_list ap)
{
	size_t	i;
	int		tmp;

	i = 0;
	if (input[i] == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
			flag->minus = TRUE;
		flag->width = ft_abs(tmp);
		i++;
	}
	else
	{
		while (is_number(input[i]))
		{
			flag->width *= 10;
			flag->width += input[i] - '0';
			i++;
		}
	}
	return (i);
}

size_t	get_width_and_prec(const char *input, t_flags *flag, va_list ap)
{
	size_t	i;

	i = 0;
	i += get_width(&input[i], flag, ap);
	if (input[i] == '.')
	{
		i++;
		flag->dot = TRUE;
		i += get_precision(&input[i], flag, ap);
	}
	return (i);
}
