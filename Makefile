# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/11 14:16:38 by ochouati          #+#    #+#              #
#    Updated: 2024/06/11 21:30:55 by ochouati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTILS = ./utils/ft_exit.c ./utils/lists/linked_init.c ./utils/lists/removeif_env.c
PARSING = ./parsing/dup_env.c ./parsing/ft_init.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline # -g -fsanitize=address
HEADERS = minishell.h
SRC = main.c $(PARSING) $(UTILS)\

NAME = minishell

OBJS = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(SRC) $(HEADERS)
	make -C libft
	$(CC) $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

run : all
	clear
	./$(NAME)

re : fclean all


.PHONY: all clean fclean re
