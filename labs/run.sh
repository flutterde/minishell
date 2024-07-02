while true
do
cc -Wall -Wextra -Werror -lreadline first_split.c ../libft/libft.a -o app
./app
done