/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redire_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:00:02 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/31 16:47:18 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	redire_handler(t_redir *redire, int	*red_fd)
{
	t_redir	*tmp;
	int		in; // red_fd[0]
	int		out; // red_fd[1]

	(void) in;
	(void) out;
	(void) red_fd;
	tmp = redire;
	while (tmp)
	{
		printf("*** BEFORE ***\n");
		printf("file: %s\n", tmp->file);
		if (tmp->type == REDIR_OUT || tmp->type == APPEND)
		{
			out = out_handler(tmp);
			printf("OUT_FD: %d\n", out);
		}
		else
			printf("REDIRECT_IN\n");
		printf("*** AFTER ***\n");
		tmp = tmp->next;
	}
	return (1); // Feel free to update this return
}
