UTILS = ./utils/ft_exit.c ./utils/lists/linked_utils1_env.c ./utils/lists/removeif_env.c \
./utils/lists/linked_utils2_env.c ./utils/helpers/ft_errno.c ./utils/helpers/get_cmd_path.c \
./utils/helpers/env_lst_to_2dchar.c ./utils/helpers/print_env.c ./utils/set_data.c \
./utils/helpers/get_absolute_path.c 

PARSING = ./utils/helpers/ft_print_lexer.c ./parsing/parsing.c ./parsing/utils/dup_env.c ./parsing/utils/ft_init.c ./parsing/utils/parse_quote_helpers.c \
./parsing/create_lexer.c ./parsing/utils/create_lexer_helpers.c ./parsing/utils/check_syntax.c \
./parsing/utils/check_syntax_helpers.c ./parsing/join_lexer.c ./parsing/ft_expander.c \
./parsing/utils/join_lexer_helpers.c ./parsing/utils/fill_redirect.c

FT_SRCS = ./src/built_in/ft_export.c ./src/built_in/ft_echo.c ./src/built_in/ft_pwd.c \
./src/ft_execve.c ./src/built_in/ft_export_no_args.c ./src/built_in/ft_cd.c  ./utils/clear_data.c 

LEX_SRCS = ./parsing/lists/lex_create.c ./parsing/lists/lex_add_back.c \
./parsing/lists/lex_getlast.c ./parsing/lists/lex_clear_list.c ./parsing/lists/lex_delete_node.c \

ADD_ONS = ./utils/ft_free.c ./parsing/lists/inred_create.c ./parsing/lists/out_create.c \
./src/built_in/is_builtin.c ./utils/helpers/ft_is_newln.c

CMD_SRCS = ./parsing/lists/cmd_utils.c ./parsing/lists/cmd_create.c ./parsing/lists/cmd_clear.c \

MORE_LSTS = ./parsing/lists/red_clear.c ./parsing/lists/red_create.c ./parsing/lists/red_utils.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline -L/goinfre/ochouati/homebrew/opt/readline/lib -I/goinfre/ochouati/homebrew/opt/readline/include # -g -fsanitize=address
HEADERS = minishell.h
SRC = main.c $(PARSING) $(MORE_LSTS) $(UTILS) $(FT_SRCS) $(LEX_SRCS) $(ADD_ONS) $(CMD_SRCS) src/execve_handler.c \

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
