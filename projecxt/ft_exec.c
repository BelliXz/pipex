#include "pipex.h"


int	ft_check_cmd(char *cmd, char **cmd_path)
{
	int		i;
	int		flag;
	char	*finalpath;

	if (!cmd || !cmd_path)
		return(0);
	i = 0;
	flag = 0;
	while (cmd_path[i])
	{
		finalpath = ft_strjoin(cmd_path[i], cmd);
		printf("\nPATH= %s", finalpath);
		if(!access(finalpath, F_OK))
		{
			flag = 1;
			free(finalpath);
			break;
		}
		free(finalpath);
		i++;
	}
	return (flag);
}

void	ft_exec(char ***cmd, char **path, char **argv)
{
	int		tpipe[2];
	pid_t	pid;
	int		fd[2];
    int     i;

	if (pipe(tpipe) == -1)
	{
		perror("Error");
		exit(1);
	}
    i = 0;
    while (cmd[i])
    {
        ft_shadowclone_jitsu(cmd[i], tpipe, fd, path);
    }
}