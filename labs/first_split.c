/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:53:04 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/03 19:07:22 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
// todo:: here , I'm spliting for && and ||.

// typedef enum { COMMAND, AND, OR, LPAREN, RPAREN } TokenType;

// cmd1 && cmd2
// cmd1 || cmd2
// cmd1 && cmd2 || cmd3
// cmd1 || cmd2 && cmd3
// (cmd1 && cmd2) || cmd3
// cmd1 && (cmd2 || cmd3)
// (cmd1 || cmd2) && cmd3
// ((cmd1 && cmd2) || cmd3) && cmd4
// cmd1 && (cmd2 || (cmd3 && cmd4))
// (cmd1 && (cmd2 || cmd3)) && cmd4
// (cmd1 || (cmd2 && cmd3)) || cmd4
// cmd1 && (cmd2 || (cmd3 && (cmd4 || cmd5)))
// (cmd1 && cmd2) || (cmd3 && cmd4)
// ((cmd1 || cmd2) && cmd3) || cmd4
// (cmd1 && (cmd2 || (cmd3 && cmd4))) || cmd5 // todo:: this is the main,
// ((cmd1 && cmd2) || (cmd3 && cmd4)) && cmd5
// cmd1 || (cmd2 && (cmd3 || (cmd4 && cmd5)))
// cmd1 && (cmd2 || (cmd3 && (cmd4 || (cmd5 && cmd6))))
// (cmd1 || cmd2) && (cmd3 || cmd4)
// cmd1 && cmd2 || cmd3 && cmd4 || cmd5

// split by && and ||, if there is a parenthesis, we will split by it first.


// ! (echo hi1 && (echo hi2 && echo hi3 || echo hiX && echo HiY)) && echo hi4 || echo hi5 || echo hi6

// ? this func indicates if the char is a parenthesis.
static int	_is_paren(char c)
{
	if (c == '(' || c == '\'' || c == '"')
		return (1);
	return (0);
}

// set the char
static void	set_char(char c, int *paren, int *sqoutes, int *dqoutes)
{
	*paren = 0;
	*sqoutes = 0;
	*dqoutes = 0;
	if (c == '(')
		*paren = 1;
	else if (c == '\'')
		*sqoutes = 1;
	else if (c == '"')
		*dqoutes = 1;
}

void	skip_word(char *str, int *i)
{
	int		paren;
	int		sqoutes; // single qoutes
	int		dqoutes; // double qoutes

	set_char(str[*i], &paren, &sqoutes, &dqoutes);
	(*i)++;
	while (str && str[*i])
	{
		if (!paren && !sqoutes && !dqoutes)
			break;
		if (str[*i] == '(')
			paren++;
		else if (str[*i] == ')')
			paren--;
		else if (str[*i] == '\'')
			sqoutes = !sqoutes;
		else if (str[*i] == '"')
			dqoutes = !dqoutes;
		(*i)++;
	}
}

int	_count_ops(char *str, char *sep)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		// skip spaces
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i])
		{
			if (_is_paren(str[i]))
				skip_word(str, &i);
			else if (str[i] == sep[0] && str[i] == sep[1])
			{
				// TODO:: how about change str[i] to CHAR1, and then split by it.
				str[i] = CHAR1; // change the char to CHAR1
				str[i + 1] = CHAR1; // change the char to CHAR1
				i += 2;
				break;
			}
			i++;
		}
	}
	return (count);
}

char	**first_split(char *str, char *sep)
{
	(void)str;
	char	**split;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	(void)j;
	(void)i;
	// todo:: count the number of && and || in the string.
	count = _count_ops(str, sep);
	ft_printf("=======> count: %d\n", count);
	if (count == 1 && str[0] == '(' && str[ft_strlen(str) - 1] == ')')
	{
		str = ft_substr(str, 1, ft_strlen(str) - 2);
		count = _count_ops(str, sep);
		ft_printf("====AFTER===> count: %d\n", count);
	}
	split = ft_split(str, CHAR1);
	ft_printf(" ---- ------ ----- After the Spliy ---- ------ ----- \n");
	ft_print_strs(split);
	ft_printf(" ---- ------ ----- End After the Spliy ---- ------ ----- \n");
	return (NULL);
}

// ! how we can split the string by && and ||. ? what first && or || ?
// ! what about change the separators to some inusual ascii characters, and then split by them with split ?
int	main(void)
{
	// char	*str = "echo hi1 && (echo hi2 && echo hi3 || echo hiX && echo HiY)) && echo hi4 || echo hi5 || echo hi6";
	// char	*str = "(ech h1 && echo hi2 && (echo hi3 || echo hiX && echo HiY) && echo hi4 || echo hi5 || echo hi6)";
	char	*str = "(ech h1 && echo hi2 && (echo hi3 || echo hiX && echo HiY) && echo hi4 || echo hi5 || echo hi6)";

	// str = readline("Enter a string: ");
	// ! Make sure that str is not a Read-Only string.
	first_split(ft_strdup(str), "||");
	// char	*join = ft_strjoin3("&&", char_to_string(CHAR1), ("||"));
	// printf("You entered: %s\n", join);
	// printf("You entered: %d\n", _is_paren(str[0]));
	return (0);
}
