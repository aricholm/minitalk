/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 11:19:58 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/08 13:16:45 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	is_flag(const char c)
{
	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (TRUE);
	return (FALSE);
}

static t_bool	put_flag(const char c, t_flags *flag)
{
	if (c == '#')
		flag->hash = TRUE;
	if (c == '0')
		flag->zero = TRUE;
	if (c == '-')
		flag->minus = TRUE;
	if (c == ' ')
		flag->space = TRUE;
	if (c == '+')
		flag->plus = TRUE;
	return (TRUE);
}

size_t	get_flags(const char *input, t_flags *flag)
{
	size_t	i;

	i = 0;
	while (is_flag(input[i]))
		put_flag(input[i++], flag);
	if (flag->zero && flag->minus)
		flag->zero = FALSE;
	return (i);
}
