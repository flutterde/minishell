/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:48:34 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/03 10:49:42 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// ? increment SHLVL
static void	__shell_level(t_env *head)
{
	char	*tmp;
	char	*tmp2;
	t_env	*target;

	target = search_env(head, "SHLVL");
	if (!target)
		return ;
	tmp = ft_itoa(ft_atoi(target->value) + 1);
	if (!tmp)
		return ;
	tmp2 = target->value;
	target->value = tmp;
	free(tmp2);
}

static t_env	*new_node(char *str)
{
	char	*key;
	char	*val;
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strchr(str, '=');
	val = ft_strdup(tmp + 1);
	key = ft_substr(str, 0, (ft_strlen(str) - ft_strlen(tmp)));
	return (ls_create_env(key, val));
}

t_env	*dup_env(char **env)
{
	t_env	*head;
	t_env	*new;
	int		i;

	if (!env || !*env)
		return (NULL);
	head = NULL;
	i = 0;
	while (env[i])
	{
		new = new_node(env[i]);
		ls_add2end_env(&head, new);
		i++;
	}
	__shell_level(head);
	return (head);
}

void	lex_env_helper(t_lex_env *e_h, char **line)
{
	while (**line && (ft_isalnum(*(*line)) || **line == '_'))
	{
		e_h->ch = char_to_str(**line);
		if (!e_h->ch)
			return ;
		e_h->str = ft_strjoin(e_h->str, e_h->ch);
		if (!e_h->str)
			return (ft_free((void **) &e_h->ch));
		ft_free((void **) &e_h->ch);
		(*line)++;
	}
	(*line)--;
}
