/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:38:09 by paradari          #+#    #+#             */
/*   Updated: 2024/03/24 15:38:12 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_dochild(char	**cmd, int OpipeI, char **path, int infile)
{
	// fd = open(infile, O_RDONLY);
	// if (fd == -1)
	// 	error_msg(ERR_INFILE);
	dup2(infile, 0);
	dup2(OpipeI[1], 1);
	close(OpipeI[0]);
	if (execve(path, cmd, NULL) == -1)
		error_msg(ERR_CMD);


}

void	ft_doparent(char **cmd, int OpipeI, char **path, int outfile)
{
	dup2(outfile, 1);
	dup2(OpipeI[0], 0);
	close(OpipeI[1]);
	if (execve(path, cmd, NULL) == -1)
		error_msg(ERR_CMD);
}

void    ft_pipex()
{
    int	OpipeI[2];
	pid_t	pid;
	char	**finalpath;

	if(pipe(OpipeI) == -1)
		error_msg(ERR_PIPE);
	pid = fork();
	if (pid == 0)
	{
		finalpath[0] = ft_findpath(path, cmd);
		ft_dochild(cmd,OpipeI,path,argv[1]);
	}
	else 
	{
		finalpath[1] = ft_findpath(path, cmd);
		ft_doparent(cmd,OpipeI,path,argv[4]);
		wait(NULL);
		dup2(OpipeI[0], 0);
		close(OpipeI[1]);
		dup2(outfile, 1);
	}
}