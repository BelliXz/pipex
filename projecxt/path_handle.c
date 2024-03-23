#include "pipex.h"

char	**ft_collect_path(char	*path)//collectpath
{
	char	**cmd_path;
	int		i;

	i = 0;
	cmd_path = ft_split(path, ':');
	while(cmd_path[i])
	{
		cmd_path[i] = ft_strrejoin(cmd_path[i], "/");
		i++;
	}
	return (cmd_path);
}

char	**ft_findpath(char **envp)//collectpath
{
	char	**cmd_path;
	int		i;
	int		p_index;

	p_index = -1;
	i = 0;
	while(envp[i])
	{
		if (!(ft_memcmp(envp[i], "PATH=", 5)))
		{
			p_index = i;
			break;
		}
		i++;
	}
	if (p_index >= 0)
	{
		cmd_path = ft_collect_path(envp[p_index] + 5);
		return (cmd_path);
	}
	return (NULL);
}