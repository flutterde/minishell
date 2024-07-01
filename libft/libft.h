/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:05:48 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/30 15:13:46 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>

# define LMA 9223372036854775807
# define LMN 9223372036854775808UL

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_atoi(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_random(int size);
// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*_ft_strchr(const char *s, int c);
size_t	_ft_strlen(const char *str);
char	*_ft_strjoin(char *s1, char *s2);
char	*_ft_strdup(char *s1);
char	*_substr(char *begin, char *end);
// PRINTF
typedef unsigned int	t_unint;

int		ft_printf(const char *str, ...);
int		_ft_puchar(char c);
int		_ft_pustr(char *str);
int		_ft_putbnr(int nb);
int		_ft_hexa(unsigned int nb, char c);
int		_ft_print_adrs(void *adrs);
int		_ft_print_u(t_unint nb);
int		ftp_sp_sn(char c, int nbr);
int		h_hashtag(t_unint nb, char c);
int		__bonus(char c, char c2, va_list ap);
bool	_is_dg(char c1, char c2);
bool	_is_hx(char c1, char c2);
bool	_is_ss(char c1, char c2);
bool	_is_speci_format(char c1, char c2);

// ADDITIONNAL
void	ft_swap(int *xp, int *yp);
void	ft_sort_int_tab(int *tab, int size);
void	ft_free_strs(char **str);
void	ft_print_string_bits(char *str);
void	ft_lstprint_str(t_list *head);
void	ft_print_strs(char **strs);
char	*ft_first_word(char *str);
char	*ft_last_word(char *str);
long	ft_atol(char *str);
void	ft_print_numbers(int c, int *arr);
int		ft_split_size(char **str);
char	***ft_split3(char *str, char c1, char c2);
char	**dup2dchar(char **str);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
void	mini_printf(int fd, const char *str, ...);
char	*char_to_string(char c);
int		ft_strcmp(char *s1, char *s2);

#endif