/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:03:49 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/09 12:34:32 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	is_conversion(const char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u')
		return (TRUE);
	else if (c == 'x' || c == 'X' || c == '%')
		return (TRUE);
	else if (c == 'n' || c == 'f' || c == 'g' || c == 'e')
		return (TRUE);
	return (FALSE);
}

static size_t	get_short(const char *input, t_flags *flag)
{
	size_t	i;

	i = 0;
	if (input[i] == 'h')
	{
		flag->lenght_modifier = HH;
		i++;
	}
	else if (is_conversion(input[i]))
		flag->lenght_modifier = H;
	else
		flag->valid = FALSE;
	return (i);
}

static size_t	get_long(const char *input, t_flags *flag)
{
	size_t	i;

	i = 0;
	if (input[i] == 'l')
	{
		flag->lenght_modifier = LL;
		i++;
	}
	else if (is_conversion(input[i]))
		flag->lenght_modifier = L;
	else
		flag->valid = FALSE;
	return (i);
}

size_t	get_modifier(const char *input, t_flags *flag)
{
	size_t	i;

	i = 0;
	if (input[i] == 'l')
	{
		i++;
		i += get_long(&input[i], flag);
	}
	if (input[i] == 'h')
	{
		i++;
		i += get_short(&input[i], flag);
	}
	return (i);
}
