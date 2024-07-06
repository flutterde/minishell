/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:17:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/06 18:08:34 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "head.h"

static int	_compare_end(char *wcard, char *file)
{
	int		i;
	int		wlen;
	int		flen;

	if (!wcard || !file)
		return (0);
	i = 0;
	wlen = ft_strlen(wcard);
	flen = ft_strlen(file);
	while ((wcard && file) && (wcard[wlen] == file[flen]))
	{
		wlen--;
		flen--;
	}
	if (wlen == 0)
		return (0);
	return (1);
}

static int	_is_a_match(char *wcard, char *file)
{
	int		i;
	int		len;

	if (!wcard || !file)
		return (0);
	i = 0;
	len = ft_strlen(wcard);
	if (wcard[i] == '*')
	{
		if (!_compare_end(wcard, file))
			return (1);
		return (0);
	}
	else if (wcard[len - 1] == '*')
	{
		if (!ft_strncmp(wcard, file, len - 1))
			return (1);
		return (0);
	}
	return (!ft_strcmp(wcard, file));
}

char	**ft_wildcard(char *str, char *dir_path)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**files;
	char			**tmp;

	if (!str || !dir_path)
		return (NULL);
	dir = opendir(dir_path);
	if (!dir)
		return (NULL);
	entry = readdir(dir);
	files = NULL;
	while (entry)
	{
		if (_is_a_match(str, entry->d_name))
		{
			tmp = files;
			files = insert_to2d_array(files, entry->d_name);
			if (tmp)
				ft_free_strs(tmp);
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (files);
}

int	main(int ac, char **av)
{
	char	**files;

	if (ac != 3)
		return (ft_printf("ERROR\n"), 1);
	files = ft_wildcard(av[1], av[2]);
	if (!files)
		return (ft_printf("NO_Files\n"), 1);
	ft_printf("Files:\n");
	ft_print_strs(files);
	ft_printf("----------------\n");
	ft_free_strs(files);
	// int i;
	// i = fork();
	// if (!i)
	// {
	// }
	// system("leaks app");
	return (0);
}
