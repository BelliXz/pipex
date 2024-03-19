/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:12:05 by paradari          #+#    #+#             */
/*   Updated: 2023/11/06 14:50:01 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	k;

	i = 0;
	k = 0;
	str = 0;
	if (*s1 == '\0')
		return (ft_strdup(""));
	if (set != 0 && s1 != 0)
	{
		j = ft_strlen(s1) - 1;
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j] && ft_strchr(set, s1[j]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 2));
		if (!str)
			return (NULL);
		while (i <= j)
			str[k++] = (char)s1[i++];
		str[k] = '\0';
	}
	return (str);
}
