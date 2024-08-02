# while true
# do
cc -Wall -Wextra -Werror ft_wildcard.c ../libft/libft.a -o app # -lreadline
./app "$1" "$2"
# done