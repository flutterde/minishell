/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:53:04 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/02 18:40:11 by ochouati         ###   ########.fr       */
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
			else if (str[i] == sep[0] || str[i] == sep[1])
			{
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
	// char	**split;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = _count_ops(str, sep);
	printf("=======> count: %d\n", count);
	// todo:: count the number of && and || in the string.
	return (NULL);
}


int	main(void)
{
	char	*str;

	str = readline("Enter a string: ");
	first_split(str, "||");
	// printf("You entered: %d\n", _is_paren(str[0]));
	return (0);
}
