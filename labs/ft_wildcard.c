/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:17:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/07 20:42:53 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "head.h"

// tests: "*_*_*.c", "*.js", "something.*", "something.*.c", "something.*.c*"
static int	is_pattern_match(char *file, char *wcard)
{
	int	i;

	i = 0;

}

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

int	main(int ac, char **av, char **envp)
{
	char	**files;
	char	**tmp;
	char	**tmp2;
	int		i = 0;

	if (ac != 3)
		return (ft_printf("ERROR\n"), 1);
	tmp = ft_split("ls", ' ');
	files = ft_wildcard(av[1], av[2]);
	if (!files)
		return (ft_printf("NO_Files\n"), 1);
	while (files && files[i])
	{
		tmp2 = tmp;
		tmp = insert_to2d_array(tmp, files[i]);
		i++;
		ft_free_strs(tmp2);
	}
	ft_printf("Files:\n");
	ft_print_strs(files);
	ft_printf("----------------\n");
	int status;
	i = fork();
	if (!i)
	{
		if(execve("/bin/ls", tmp, envp))
		{
			ft_printf("ERROR\n");
			exit(1);
		}
	}
	waitpid(i, &status, 0);
	ft_free_strs(files);
	ft_free_strs(tmp);
	// system("leaks app");
	return (0);
}
