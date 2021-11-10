/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 10:24:46 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/19 11:44:59 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	use_string(t_flags flag, va_list ap)
{
	char	*str;
	size_t	len;
	size_t	char_counter;
	t_bool	must_free;

	char_counter = 0;
	must_free = FALSE;
	str = va_arg(ap, char *);
	if (!str && (flag.precision >= 6 || !flag.dot))
	{
		str = ft_strdup("(null)");
		must_free = TRUE;
	}
	len = ft_strlen(str);
	if (flag.precision < len && flag.dot)
		len = flag.precision;
	if (flag.width > len && !flag.minus)
		char_counter += write_spaces(flag.width - len);
	char_counter += write_string(str, len);
	if (flag.width > len && flag.minus)
		char_counter += write_spaces(flag.width - len);
	if (must_free)
		free (str);
	return (char_counter);
}
