/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_no_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 14:25:09 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/05 18:13:21 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	__ft_swap(char **a, char **b)
{
	char	*c;

	c = NULL;
	c = *a;
	*a = *b;
	*b = c;
}

static t_env	*sort_env(t_env *env)
{
	t_env	*top;
	t_env	*tmp;

	top = env;
	tmp = env;
	env = (env)->next;
	while (env)
	{
		while (tmp)
		{
			if (ft_strcmp(tmp->key, env->key) > 0)
			{
				__ft_swap(&(tmp)->key, &(env)->key);
				__ft_swap(&(tmp)->value, &(env)->value);
			}
			tmp = tmp->next;
		}
		tmp = top;
		env = (env)->next;
	}
	return (top);
}

int	ft_export_no_args(t_env *env)
{
	t_env	*sorted_env;
	t_env	*new_env;
	char	**envp;

	if (!env)
		return (0);
	envp = env_lst_to_2dchar(env);
	if (!envp)
		return (0);
	new_env = dup_env(envp);
	if (!new_env)
		return (0);
	ft_free_strs(envp);
	sorted_env = sort_env(new_env);
	if (!sorted_env)
		return (0);
	while (sorted_env)
	{
		ft_printf("declare -x %s=%s\n", sorted_env->key, sorted_env->value);
		sorted_env = sorted_env->next;
	}
	ls_clear_env(&new_env);
	return (1);
}
