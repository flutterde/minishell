UTILS = ./utils/ft_exit.c ./utils/lists/linked_utils1_env.c ./utils/lists/removeif_env.c \
./utils/lists/linked_utils2_env.c ./utils/helpers/ft_errno.c ./utils/helpers/get_cmd_path.c \
./utils/helpers/env_lst_to_2dchar.c ./utils/helpers/print_env.c ./utils/set_data.c \
./utils/helpers/print_lexer.c

FT_SRCS = ./src/built_in/ft_export.c ./src/built_in/ft_echo.c ./src/built_in/ft_pwd.c \
./src/ft_execve.c \
./utils/helpers/env_lst_to_2dchar.c ./utils/helpers/print_env.c 

PARSING = ./parsing/dup_env.c ./parsing/ft_init.c ./parsing/utils/initial_split_line.c \
./parsing/utils/parse_quote.c ./parsing/utils/parse_quote_helpers.c ./parsing/create_lexer.c \
./parsing/utils/create_lexer_helpers.c

FT_SRCS = ./src/built_in/ft_export.c ./src/built_in/ft_echo.c ./src/built_in/ft_pwd.c \
./src/ft_execve.c ./src/built_in/ft_export_no_args.c

LEX_SRCS = ./parsing/lists/lex_new_node.c ./parsing/lists/lex_add_back.c \
./parsing/lists/lex_getlast.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline # -g -fsanitize=address
HEADERS = minishell.h
SRC = main.c $(PARSING) $(UTILS) $(FT_SRCS) $(LEX_SRCS) \

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
