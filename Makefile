# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdionna <cdionna@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 18:33:20 by cdionna           #+#    #+#              #
#    Updated: 2021/07/08 19:18:19 by cdionna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server

PROGRAM = client

HEADER = include/minitalk.h

UTILS = $(addprefix src/, utils_1.c utils_2.c)

O_FILE = $(UTILS:.c=.o)

C_FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(O_FILE)
	@gcc $(C_FLAGS) $(O_FILE) src/server.o -o $(NAME)
	@gcc $(C_FLAGS) $(O_FILE) src/client.o -o $(PROGRAM)

%.o: %.c $(HEADER)
	@gcc -c $(C_FLAGS) $< -o $@
	@gcc -c $(C_FLAGS) src/client.c -o src/client.o
	@gcc -c $(C_FLAGS) src/server.c -o src/server.o
	@gcc -c $(C_FLAGS) src/bonus/server_bonus.c -o src/bonus/server_bonus.o
	@gcc -c $(C_FLAGS) src/bonus/client_bonus.c -o src/bonus/client_bonus.o

clean:
	@rm -rf $(O_FILE) src/client.o src/server.o src/bonus/client_bonus.o src/bonus/server_bonus.o

fclean: clean
	@rm -rf $(NAME) $(PROGRAM)

re:		fclean all

bonus: $(O_FILE)
	@gcc $(C_FLAGS) $(O_FILE) src/bonus/server_bonus.o -o $(NAME)
	@gcc $(C_FLAGS) $(O_FILE) src/bonus/client_bonus.o -o $(PROGRAM)

.PHONY : all clean fclean re bonus