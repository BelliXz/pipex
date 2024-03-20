/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:27:03 by paradari          #+#    #+#             */
/*   Updated: 2024/03/19 14:27:05 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_countwords(char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == '\0')
				return (counter);
		}
		i++;
	}
	return (counter);
}

void	ft_setsplits(char *str, char *s, size_t wordlen, size_t *index)
{
	size_t	i;

	i = 0;
	while (i < wordlen)
	{
		str[i] = s[*index - 1 + i];
		i++;
	}
	*index += i;
	str[i] = '\0';
}

char	*ft_splitsallo(char *s, char c, size_t *index)
{
	char	*splitsword;
	size_t	wordlen;

	wordlen = 0;
	while (s[*index] != '\0' && wordlen == 0)
	{
		if (s[*index] != c)
		{
			while (s[*index + wordlen] != c && s[*index + wordlen] != '\0')
			{
				wordlen++;
			}
			splitsword = (char *)malloc(sizeof(char) * (wordlen + 1));
			if (!splitsword)
				return (NULL);
		}
		*index += 1;
	}
	ft_setsplits(splitsword, s, wordlen, index);
	return (splitsword);
}

void	ft_free(char **splits)
{
	size_t	i;

	i = 0;
	while (splits[i])
	{
		free(splits[i]);
		i++;
	}
	free(splits);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;
	size_t	index;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = ft_countwords((char *)s, c);
	splits = (char **)malloc(sizeof(char *) * (words + 1));
	if (!splits)
		return (NULL);
	index = 0;
	i = 0;
	while (i < words)
	{
		splits[i] = ft_splitsallo((char *)s, c, &index);
		if (!splits[i])
		{
			ft_free(splits);
			return (NULL);
		}
		i++;
	}
	splits[i] = NULL;
	return (splits);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = s1;
	str2 = s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

int	ft_check_cmd(char **cmd)
{
	return 0;
}

// void	ft_delprefix(char *cmd_path)
// {

// }

char	**ft_collect_path(char	*path)//collectpath
{
	char	**cmd_path;
	int		i;

	i = 0;
	cmd_path = ft_split(path, ':');
	return (cmd_path);
}

// void	*ft_memchr(const void *s, int c, size_t n)//collectpath
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (*(unsigned char *)(s + i) == (unsigned char)c)
// 			return ((void *)(s + i));
// 		i++;
// 	}
// 	return (0);
// }


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

// int	ft_check_infile(char *infile)
// {
// 	int	fd;

// 	fd = open(*infile, RD_ONLY)
// 	if()
// }

int	main(int argc, char **argv, char **envp)
{
	char	***cmd;
	char 	**cmd_path;
	int		i;
	int		j;

	cmd_path = ft_findpath(envp);
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
		cmd[i - 2] = ft_split(argv[i], ' ');//collectcmd
    cmd[2] = NULL;
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
	i = 0;
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

// main()
// {
	// ft_init_pipex()
	// ft_check_args()
	// ft_parse_cmds()
	// ft_parse_args()
	// while (cmds)
		// ft_exec()
	// ft_cleanup()
// }
// ft_exec()
// {
	// pipe()
	// fork()
	// if (child)
	// {
		// dup2()
		// execve()
	// }
	// else
	// {
		// close()
	// }
// }