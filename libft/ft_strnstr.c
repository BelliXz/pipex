/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 18:01:51 by paradari          #+#    #+#             */
/*   Updated: 2023/11/02 13:31:09 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*need == '\0')
		return ((char *)str);
	while (i < len && str[i])
	{
		j = 0;
		while (str[i + j] && need[j] && i + j < len && str[i + j] == need[j])
			j++;
		if (!need[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
