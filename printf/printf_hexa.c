/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 13:21:23 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/09 12:34:13 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hex_lenght(unsigned long long integer, t_lenght_mod mod)
{
	size_t	i;

	i = 0;
	if (mod == NONE)
		integer = (unsigned int) integer;
	if (mod == L)
		integer = (unsigned long) integer;
	if (mod == H)
		integer = (unsigned short) integer;
	if (mod == HH)
		integer = (unsigned char) integer;
	while (integer > 0)
	{
		integer = integer / 16;
		i++;
	}
	return (i);
}

static char	gethex(unsigned int num, t_type type)
{
	if (num < 10)
		return (num + '0');
	if (num < 16)
	{
		if (type == HEXA_UPPER)
			return ('A' + (num - 10));
		return ('a' + (num - 10));
	}
	return (0);
}

char	*itohex(unsigned long long integer, t_type type, t_lenght_mod modifier)
{
	size_t	i;
	char	*hex;

	if (type == POINTER && !integer)
		return (ft_strdup("0x0"));
	i = hex_lenght(integer, modifier);
	hex = malloc((i + 1) * sizeof(char));
	if (!hex)
		return (0);
	hex[i] = 0;
	while (i > 0)
	{
		hex[i - 1] = gethex(integer % 16, type);
		integer = integer / 16;
		i--;
	}
	return (hex);
}
