/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 11:41:35 by aricholm          #+#    #+#             */
/*   Updated: 2021/06/29 13:40:39 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	use_char(t_flags flag, va_list ap)
{
	char	c;
	size_t	char_counter;

	char_counter = 1;
	c = (unsigned char) va_arg(ap, int);
	if (flag.width > 1 && !flag.minus)
		char_counter += write_spaces(flag.width - 1);
	write(1, &c, 1);
	if (flag.width > 1 && flag.minus)
		char_counter += write_spaces(flag.width - 1);
	return (char_counter);
}
