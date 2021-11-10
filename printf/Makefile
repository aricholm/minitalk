# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 16:49:20 by aricholm          #+#    #+#              #
#    Updated: 2021/07/19 11:38:47 by aricholm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wall -Wextra
NAME = libftprintf.a
LIBFT = ./libft/libft.a
OBJS = \
ft_printf.o printf_utils.o \
printf_flags.o printf_width.o printf_modifier.o printf_conversions.o \
printf_hexa.o decimal_utils.o \
use_string.o use_char.o use_hexa.o use_decimal.o

all : $(NAME)

bonus : $(NAME)
	
$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp $(LIBFT) $(NAME)
	ar rcs $@ $^
	
%.o: %.c
	$(CC) -c $(CFLAGS)  -o $@  $^

clean:
	echo "Remove .o  ..."
	rm -f $(OBJS) $(BONUS)
	$(MAKE) clean -C ./libft

fclean: clean
	echo "Remove lib ..."
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re bonus