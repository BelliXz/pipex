/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:59:02 by paradari          #+#    #+#             */
/*   Updated: 2024/03/20 14:59:05 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	***cmd;
	int		i;
	int		j;

	if(argc != 5)
	{
		printf ("Error input\n");
		return (0);
	}
	i = 1;
	cmd = malloc(sizeof(char **) * 3);
	if (!cmd)
	{
		free(cmd);
		return (0);
	}
	while (i++ < 3)
		cmd[i - 2] = ft_split(argv[i], ' ');
    cmd[2] = NULL;
	i = 0;
	while(cmd[i])
	{
		j = 0;
		while (cmd[i][j])
		{
			printf("from index[%d][%d] : %s\n", i, j, cmd[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
