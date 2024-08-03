/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:19:40 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/03 11:59:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	next_del(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]) && str[i] != '$'
		&& str[i] != QUOTE && str[i] != DOUBLE_QUOTE)
		i++;
	return (i);
}

static int	get_env(t_data *data, char **str, int fd)
{
	t_env	*found;
	char	*key;
	int		i;
	char	*status;

	status = ft_itoa(g_status);
	if (!str || !*str)
		return (0);
	if (**str && **str == '?')
		return (write(fd, status, ft_strlen(status)),
			ft_free((void **) &status), 1);
	ft_free((void **) &status);
	i = next_del(*str);
	if (!i)
		return (write(fd, "$", 1), 1);
	key = ft_substr(*str, 0, next_del(*str));
	if (!key)
		return (0);
	found = search_env(data->env, key);
	if (!found)
		return (ft_free((void **) &key), *str += i - 1, 0);
	write(fd, found->value, ft_strlen(found->value));
	*str += i - 1;
	ft_free((void **) &key);
	return (1);
}

int	heredoc_expand(t_data *data, char *str, int fd)
{
	char	*tmp;

	tmp = str;
	while (*str)
	{
		if (*str != '$')
			write(fd, str, 1);
		else
		{
			str++;
			get_env(data, &str, fd);
		}
		if (*str != '$')
			str++;
	}
	return (1);
}

static void	__read_fn(t_data *data, t_redir *node, int fd)
{
	char	*str;
	char	*trimmed;

	str = readline("HereDoc> ");
	trimmed = ft_strtrim(str, "\n");
	ft_free((void **)&str);
	while (trimmed && ft_strcmp(trimmed, node->delim))
	{
		if (ft_strchr(trimmed, '$') && node->to_expand)
			heredoc_expand(data, trimmed, fd);
		else
			write(fd, trimmed, ft_strlen(trimmed));
		write(fd, "\n", 1);
		ft_free((void **)&trimmed);
		str = readline("HereDoc> ");
		trimmed = ft_strtrim(str, "\n");
		ft_free((void **)&str);
	}
	ft_free((void **)&trimmed);
	close(fd);
}

int	ft_heredoc(t_data *data, t_redir *node, int *redfd)
{
	int	fd;
	char	*gpath;

	gpath = __generate_path();
	if (!gpath)
		return (*redfd = -1,  -1);
	fd = open(gpath, O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd < 0)
		return (free(gpath), perror("Error: "), *redfd = -1, -1);
	__read_fn(data, node, fd);
	if (node->is_last)
	{
		fd = open(gpath, O_RDONLY);
		if (fd < 0)
			return (free(gpath), perror("Error: "), *redfd = -1, -1);
		return (free(gpath), *redfd = fd, fd);
	}
	return (free(gpath), -2);
}
