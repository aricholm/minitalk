/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:28:44 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/10 14:38:30 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

size_t	write_string(const char *str, size_t len)
{
	write(1, str, len);
	return (len);
}

size_t	write_spaces(size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		write(1, " ", 1);
		i++;
	}
	return (i);
}

void	init_flag(t_flags *flag)
{
	flag->hash = FALSE;
	flag->zero = FALSE;
	flag->minus = FALSE;
	flag->space = FALSE;
	flag->plus = FALSE;
	flag->width = 0;
	flag->dot = FALSE;
	flag->precision = 0;
	flag->lenght_modifier = NONE;
	flag->type = INVALID;
	flag->lenght = 0;
	flag->valid = TRUE;
}
