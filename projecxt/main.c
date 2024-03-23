#include "pipex.h"

int	ft_check_infile(char *infile)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if(fd == -1)
	{
		perror(infile);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	***cmd;
	char 	**cmd_path;
	int		i;
	int		j;

	if (ft_check_infile(argv[i]))
		return (0);
	cmd_path = ft_findpath(envp);
	if(argc != 5)
	{
		printf ("Error input\n");
		return (0);
	}
	cmd = malloc(sizeof(char **) * 3);
	if (!cmd)
	{
		free(cmd);
		return (0);
	}
	i = 1;
	while (i++ < 3)
		cmd[i - 2] = ft_split(argv[i], ' ');//collectcmd
    cmd[2] = NULL;
	i = 0;
	while (cmd[i] && (ft_check_cmd(cmd[i][0], cmd_path)))
		i++;
	printf("\ni afterchk = %d\n",i);
	if(i < 2)
	{
		printf("command not found: %s\n", cmd[i][0]);
	}
	else
		printf("cmd good\n");
	ft_exec(cmd, cmd_path, argv);
	// printf("%s\n", argv[2]);
	// if(execve(argv[2], "ls -l", NULL))
	// 	perror("Error");
	// if(ft_check_cmd(cmd_path, cmd) && ft_check_infile(argv[1]))
	// {
		
	// }
	// i = 0;
	// while(envp[i])
	// {
		// j = 0;
		// while (cmd_path[i][j])
		// {
			// printf("from index[%d][%d] : %s\n", i, j, envp[37]);
			// j++;
		// }
		// i++;
	// }
	// i = 0;
	while(cmd_path[i])
	{
		j = 0;
		// while (cmd_path[i][j])
		// {
			printf("from index[%d][%d] : %s\n", i, j, cmd_path[i]);
			j++;
		// }
		i++;
	}
	return (0);	
}