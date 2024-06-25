#include "head.h"

// [this function search and return the path of a giving command]::DONE
char	*cmd_path(char *path, char *cmd)
{
	char	*new;
	char	**spl;
	int		i;

	if (!path || !cmd)
		return (NULL);
	spl = ft_split(path, ':');
	if (!spl)
		return (NULL);
	i = 0;
	while (spl[i])
	{
		new = ft_strjoin3(spl[i], "/", cmd);
		if (!new)
			return (ft_free_strs(spl), NULL);
		if (!access(new, X_OK))
			return (ft_free_strs(spl), new);
		free(new);
		i++;
	}
	return (ft_free_strs(spl), NULL);
}
