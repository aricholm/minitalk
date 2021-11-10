# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aricholm <aricholm@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 18:32:56 by aricholm          #+#    #+#              #
#    Updated: 2021/11/05 11:07:24 by aricholm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERV	= server
NAME_CLNT	= client
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

OBJ_CLIENT = ./src/minitalk_client.o
OBJ_SERVER = ./src/minitalk_server.o

all: $(NAME_SERV) $(NAME_CLNT)

$(NAME_SERV): $(OBJ_SERVER)
	$(MAKE) -C ./printf
	$(CC) -o $(NAME_SERV) $(OBJ_SERVER) -Lprintf -lftprintf

$(NAME_CLNT): $(OBJ_CLIENT)
	$(MAKE) -C ./printf
	$(CC) -o $(NAME_CLNT) $(OBJ_CLIENT) -Lprintf -lftprintf

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	echo "Remove .o  ..."
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C ./printf clean

fclean: clean
	echo "Remove executables and libraries ..."
	rm -f $(NAME_SERV) $(NAME_CLNT)
	$(MAKE) -C ./printf fclean

re: fclean all

.PHONY: all clean fclean re