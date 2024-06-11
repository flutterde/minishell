/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:47:55 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/11 19:06:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DATA_H
# define MINISHELL_DATA_H

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

#endif