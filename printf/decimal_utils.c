/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:45:57 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/08 12:50:15 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	absolute(long long integer)
{
	if (integer < 0)
		return (-integer);
	return (integer);
}

static size_t	decimal_lenght(long long integer)
{
	size_t	lenght;

	lenght = 0;
	while (integer != 0)
	{
		lenght++;
		integer = integer / 10;
	}
	return (lenght);
}

char	*get_absolute_as_string(long long integer)
{
	char	*string;
	size_t	lenght;

	if (integer == -9223372036854775807 - 1)
		return (ft_strdup("9223372036854775808"));
	integer = absolute(integer);
	lenght = decimal_lenght(integer);
	string = malloc((lenght + 1) * sizeof(char));
	if (!string)
		return (0);
	string[lenght] = 0;
	while (lenght > 0)
	{
		string[lenght - 1] = integer % 10 + '0';
		integer = integer / 10;
		lenght--;
	}
	return (string);
}
