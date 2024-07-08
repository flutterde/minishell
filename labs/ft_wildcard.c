/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:17:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/08 18:49:17 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include "head.h"

// tests: "*_*_*.c", "*.js", "something.*", "something.*.c", "something.*.c*"
static int	is_matching(char *wcard, char *file)
{
	if (*wcard == '\0' && *file == '\0')
		return (0);
	if (*wcard == '*')
	{
		if (!is_matching(wcard + 1, file) || (*file != '\0' && !is_matching(wcard, file + 1)))
			return (0);
		else
			return (1);
	}
	if (*wcard == *file)
		return (is_matching(wcard + 1, file + 1));
	return (1);
}

// static int	_compare_end(char *wcard, char *file)
// {
// 	int		i;
// 	int		wlen;
// 	int		flen;

// 	if (!wcard || !file)
// 		return (0);
// 	i = 0;
// 	wlen = ft_strlen(wcard);
// 	flen = ft_strlen(file);
// 	while ((wcard && file) && (wcard[wlen] == file[flen]))
// 	{
// 		wlen--;
// 		flen--;
// 	}
// 	if (wlen == 0)
// 		return (0);
// 	return (1);
// }

// static int	_is_a_match(char *wcard, char *file)
// {
// 	int		i;
// 	int		len;

// 	if (!wcard || !file)
// 		return (0);
// 	i = 0;
// 	len = ft_strlen(wcard);
// 	if (wcard[i] == '*')
// 	{
// 		if (!_compare_end(wcard, file))
// 			return (1);
// 		return (0);
// 	}
// 	else if (wcard[len - 1] == '*')
// 	{
// 		if (!ft_strncmp(wcard, file, len - 1))
// 			return (1);
// 		return (0);
// 	}
// 	return (!ft_strcmp(wcard, file));
// }

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
		if (!is_matching(str, entry->d_name))
		{
			// ft_printf("file:: %s added\n", entry->d_name);
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
	(void) envp;
	char	**files;
	// char	**tmp;
	// char	**tmp2;
	// int		i = 0;

	if (ac != 3)
		return (ft_printf("ERROR\n"), 1);
	// tmp = ft_split("ls", ' ');
	files = ft_wildcard(av[1], av[2]);
	if (!files)
		return (ft_printf("NO_Files\n"), 1);
	// while (files && files[i])
	// {
	// 	tmp2 = tmp;
	// 	tmp = insert_to2d_array(tmp, files[i]);
	// 	i++;
	// 	ft_free_strs(tmp2);
	// }
	ft_printf("Files:\n");
	ft_print_strs(files);
	ft_printf("----------------\n");
	// int status;
	// i = fork();
	// if (!i)
	// {
	// 	if(execve("/bin/ls", tmp, envp))
	// 	{
	// 		ft_printf("ERROR\n");
	// 		exit(1);
	// 	}
	// }
	// waitpid(i, &status, 0);
	// ft_free_strs(files);
	// ft_free_strs(tmp);
	// system("leaks app");
	return (0);
}
