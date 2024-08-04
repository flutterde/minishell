/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirect_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:27:17 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/04 12:14:39 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_space_middle(char *str)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split(str, ' ');
	while (arr && arr[i])
		i++;
	ft_free_strs(arr);
	if (i > 1)
		return (1);
	return (0);
}

static void	only_space(t_lex **lex, t_cmd_utils *utils)
{
	if (((*lex)->prev->type == W_SPACE || is_redirection((*lex)->prev))
		&& ((*lex)->next && (*lex)->next->type == W_SPACE))
		utils->is_ambiguous = true;
	if ((*lex)->next && (*lex)->next->type == QUOTE
		&& consec_quote((*lex)->next, QUOTE))
		utils->is_ambiguous = true;
	else if ((*lex)->next && (*lex)->next->type == DOUBLE_QUOTE
		&& consec_quote((*lex)->next, DOUBLE_QUOTE))
		utils->is_ambiguous = true;
	if ((*lex)->prev && consec_quote_rev((*lex)->prev, QUOTE))
		utils->is_ambiguous = true;
	else if ((*lex)->prev && consec_quote_rev((*lex)->prev, DOUBLE_QUOTE))
		utils->is_ambiguous = true;
}

static void	join_and_check(t_lex **lex, t_cmd_utils *utils, char **str)
{
	if ((*lex) && (*lex)->type == ENV && (*lex)->status == GENERAL)
	{
		if (!ft_strlen((*lex)->string) 
			&& (((*lex)->prev->type == W_SPACE 
					&& ((*lex)->next && (*lex)->next->type == W_SPACE))
				|| is_redirection((*lex)->prev)))
			utils->is_ambiguous = true;
		else if (ft_strlen((*lex)->string) == 1 
			&& ft_isspace((*lex)->string[0]))
			only_space(lex, utils);
		else if (ft_strlen((*lex)->string) > 1 
			&& ft_isspace((*lex)->string[0]))
			left_space(lex, utils);
		else if (ft_strlen((*lex)->string) > 1 
			&& ft_isspace((*lex)->string[ft_strlen((*lex)->string) - 1]))
			right_space(lex, utils);
		else if (is_space_middle((*lex)->string))
			utils->is_ambiguous = true;
	}
	*str = ft_strjoin(*str, (*lex)->string);
}

char	*get_file_amb(t_lex **lex, t_cmd_utils *utils)
{
	char	*arr[2];

	arr[0] = ft_strdup("");
	if (!arr[0])
		return (NULL);
	arr[1] = NULL;
	while ((*lex) && (*lex)->type != W_SPACE && (*lex)->type != PIPELINE
		&& !is_redirection((*lex)))
	{
		if ((*lex)->type == QUOTE || (*lex)->type == DOUBLE_QUOTE)
		{
			arr[1] = get_str(lex);
			if (!arr[1])
				return (NULL);
			arr[0] = ft_strjoin(arr[0], arr[1]);
			ft_free((void **)&arr[1]);
		}
		else
			join_and_check(lex, utils, &arr[0]);
		if (!arr[0])
			return (NULL);
		(*lex) = (*lex)->next;
	}
	return (arr[0]);
}
