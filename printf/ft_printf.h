/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 01:39:07 by aricholm          #+#    #+#             */
/*   Updated: 2021/07/09 12:31:29 by aricholm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef enum e_bool{FALSE, TRUE}	t_bool;

typedef enum e_type{
	INVALID,
	CHAR,
	STRING,
	POINTER,
	DECIMAL,
	INTEGER,
	UNSIGNED,
	HEXA,
	HEXA_UPPER,
	PERCENT,
	CHARS_WRITTEN,
	DOUBLE_F,
	DOUBLE_G,
	DOUBLE_E
}	t_type;

typedef enum e_lenght_mod{
	NONE,
	L,
	LL,
	H,
	HH
}	t_lenght_mod;

typedef struct s_flags{
	t_bool				hash;
	t_bool				zero;
	t_bool				minus;
	t_bool				space;
	t_bool				plus;

	size_t				width;
	t_bool				dot;
	size_t				precision;
	t_lenght_mod		lenght_modifier;

	t_type				type;
	size_t				lenght;
	t_bool				valid;
}	t_flags;

int		ft_printf(const char *input, ...);

size_t	ft_strlen(const char *s);
size_t	write_string(const char *str, size_t len);
size_t	write_spaces(size_t len);
void	init_flag(t_flags *flag);

size_t	get_flags(const char *input, t_flags *flag);
size_t	get_width_and_prec(const char *input, t_flags *flag, va_list ap);
size_t	get_modifier(const char *input, t_flags *flag);
size_t	get_conversion(const char input, t_flags *flag);

size_t	use_string(t_flags flag, va_list ap);
size_t	use_char(t_flags flag, va_list ap);
size_t	use_hexa(t_flags flag, va_list ap);
size_t	use_decimal(t_flags flag, va_list ap);

char	*itohex(unsigned long long integer, t_type type, t_lenght_mod modifier);
char	*get_absolute_as_string(long long integer);

#endif