/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:28:02 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/07 18:56:20 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	default_precision(const char input, t_flags *flag)
{
	if (input == 'd' || input == 'i')
		flag->precision = 1;
	if (input == 'u' || input == 'x' || input == 'X')
		flag->precision = 1;
	if (input == 'e' || input == 'f' || input == 'g')
		flag->precision = 6;
}

static void	get_bonus(const char input, t_flags *flag)
{
	if (input == 'n')
		flag->type = CHARS_WRITTEN;
	if (input == 'f')
		flag->type = DOUBLE_F;
	if (input == 'g')
		flag->type = DOUBLE_G;
	if (input == 'e')
		flag->type = DOUBLE_E;
	if (!flag->dot)
		default_precision(input, flag);
}

size_t	get_conversion(const char input, t_flags *flag)
{
	if (input == 'c')
		flag->type = CHAR;
	if (input == 's')
		flag->type = STRING;
	if (input == 'p')
		flag->type = POINTER;
	if (input == 'd')
		flag->type = DECIMAL;
	if (input == 'i')
		flag->type = INTEGER;
	if (input == 'u')
		flag->type = UNSIGNED;
	if (input == 'x')
		flag->type = HEXA;
	if (input == 'X')
		flag->type = HEXA_UPPER;
	if (input == '%')
		flag->type = PERCENT;
	get_bonus(input, flag);
	if (flag->type == INVALID)
		flag->valid = FALSE;
	return (1);
}
