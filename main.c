/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:12:44 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/12 16:33:56 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	(void)env;
	// int i = 0;
	t_env *head = NULL;
	t_env *tmp = NULL;
	
	// while (i < 5)
	// {
	// 	t_env *en = ls_create_env(ft_itoa(i), ft_strdup("sonthing"));
	// 	ls_add2end_env(&head, en);
	// 	i++;
	// }
	head = dup_env(env);
	tmp = head;
	while (head)
	{
		ft_printf("the Result: KEY (%s) VALUE (%s).\n", head->key, head->value);
		head = head->next;
	}
	head = tmp;
	removeif_env(&head, "USER");
	ft_printf("-------------  ------- --- ------ ------ ------- -\n");
	while (head)
	{
		ft_printf("the Result: KEY (%s) VALUE (%s).\n", head->key, head->value);
		head = head->next;
	}
	ft_printf("-------------  ------- --- ------ ------ ------- -\n");
	head = tmp;
	ls_clear_env(&head);
	while (head)
	{
		ft_printf("the Result: KEY (%s) VALUE (%s).\n", head->key, head->value);
		head = head->next;
	}
	
	// char	*line;
	// t_env	envs;

	// ft_init(ac, av, env, &envs);
	// while (1)
	// {
	// 	line = readline(M_NAME);
	// 	add_history(line);
	// 	if (ft_strncmp(line, "exit", 4) == 0)
	// 	{
	// 		printf("Goodbye!\n");
	// 		free(line);
	// 		exit(0);
	// 	}
	// 	printf("%s\n", line);
	// 	free(line);
	// 	line = NULL;
	// }
	return (0);
}
