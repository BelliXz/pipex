/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:07:05 by paradari          #+#    #+#             */
/*   Updated: 2023/11/05 18:44:32 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
