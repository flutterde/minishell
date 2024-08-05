UTILS = ./utils/ft_exit.c ./utils/lists/linked_utils1_env.c ./utils/lists/removeif_env.c \
./utils/lists/linked_utils2_env.c ./utils/helpers/ft_errno.c ./utils/helpers/get_cmd_path.c \
./utils/helpers/env_lst_to_2dchar.c ./utils/helpers/print_env.c ./utils/set_data.c \
./utils/helpers/get_absolute_path.c ./utils/printers.c

PARSING = ./parsing/parsing.c ./parsing/utils/dup_env.c \
./parsing/create_lexer.c ./parsing/utils/create_lexer_helpers.c ./parsing/utils/check_syntax.c \
./parsing/utils/check_syntax_helpers.c ./parsing/join_lexer.c ./parsing/ft_expander.c \
./parsing/utils/join_lexer_helpers.c ./parsing/utils/fill_redirect.c ./parsing/lists/red_utils_2.c \
./parsing/utils/fill_redirect_helper.c ./parsing/utils/ambiguous.c \
./parsing/utils/wildcards_utils.c ./parsing/utils/wildcard.c

FT_SRCS = ./src/built_in/ft_export.c ./src/built_in/ft_echo.c ./src/built_in/ft_pwd.c \
./src/built_in/ft_export_no_args.c ./src/built_in/ft_cd.c  ./utils/clear_data.c src/utils/redire_handler.c

LEX_SRCS = ./parsing/lists/lex_create.c ./parsing/lists/lex_add_back.c \
./parsing/lists/lex_getlast.c ./parsing/lists/lex_clear_list.c ./parsing/lists/lex_delete_node.c \

ADD_ONS = ./utils/ft_free.c \
./src/built_in/is_builtin.c ./utils/helpers/ft_is_newln.c ./src/exec/exec_handler.c \
./src/built_in/unset_handler.c ./src/built_in/exit_handler.c ./src/exec/exec_handler_utils.c \

REDIR_SECS = src/utils/exec_redirections.c src/herdoc/herdoc_handler.c ./src/utils/redirections_utils.c \

CMD_SRCS = ./parsing/lists/cmd_utils.c ./parsing/lists/cmd_create.c ./parsing/lists/cmd_clear.c \
./src/exec/exec_utils.c 

MORE_LSTS = ./parsing/lists/red_clear.c ./parsing/lists/red_create.c ./parsing/lists/red_utils.c \
./parsing/lists/str_lst.c ./parsing/lists/str_lst2arr.c 

CC = cc
CFLAGS = -Wall -Wextra -Werror -lreadline  -L/goinfre/$(USER)/homebrew/opt/readline/lib -I/goinfre/$(USER)/homebrew/opt/readline/include # -g -fsanitize=address
# LDFLAGS = -L/usr/include/readline -lreadline
HEADERS = minishell.h
SRC = main.c $(PARSING) $(MORE_LSTS) $(UTILS) $(REDIR_SECS) $(FT_SRCS) $(LEX_SRCS) $(ADD_ONS) $(CMD_SRCS) \

NAME = minishell_bonus

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	make -C ../libft
	$(CC) $(CFLAGS) $(SRC) ../libft/libft.a -o $(NAME)
# $(CC) $(CFLAGS) $(SRC) $(LDFLAGS) libft/libft.a -o $(NAME) # in linux

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ../libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ../libft
	rm -rf $(NAME)

run : all
	clear
	./$(NAME)

re : fclean all

.PHONY: all clean fclean re
