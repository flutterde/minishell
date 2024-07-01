SRC = ./ft_atoi.c ./ft_isalnum.c ./ft_strchr.c ./ft_isascii.c ./ft_isdigit.c ./ft_toupper.c ./ft_tolower.c ./ft_isprint.c ./ft_strlen.c ./ft_isalpha.c ./ft_memset.c ./ft_bzero.c ./ft_strtrim.c\
./ft_strncmp.c ./ft_memcpy.c ./ft_strnstr.c ./ft_strrchr.c ./ft_memcmp.c \
./ft_memchr.c ./ft_memmove.c ./ft_split.c ./ft_striteri.c ./ft_strmapi.c ./ft_strlcat.c \
./ft_strlcpy.c ./ft_calloc.c ./ft_strdup.c ./ft_substr.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_itoa.c ./ft_strjoin.c  ./ft_random.c ft_lstprint_str.c\
get_next_line_utils_bonus.c get_next_line_bonus.c  handler_bonus.c ft_printf.c\
macros_bonus.c ft_helpers.c ft_hexa_handler.c ./ft_swap.c ./ft_sort_int_tab.c ./ft_free_strs.c ./ft_print_string_bits.c\
./ft_lstnew_bonus.c ./ft_lstadd_front_bonus.c ./ft_lstsize_bonus.c ./ft_lstlast_bonus.c ./ft_lstadd_back_bonus.c \
./ft_lstdelone_bonus.c ./ft_lstclear_bonus.c ./ft_lstiter_bonus.c ./ft_lstmap_bonus.c \
./ft_print_strs.c  ft_first_word.c ft_last_word.c ft_atol.c ft_print_numbers.c ft_split3.c\
ft_split_size.c ./dup2dchar.c ./ft_strjoin3.c ./mini_printf.c ./char_to_string.c ./ft_strcmp.c


CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

AR = ar rcs

RM = rm -rf


NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all