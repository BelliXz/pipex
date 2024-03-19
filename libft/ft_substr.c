/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:01:46 by paradari          #+#    #+#             */
/*   Updated: 2023/11/06 13:43:15 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	if (!s || start >= slen)
		len = 0;
	else if (len >= slen || start + len >= slen)
		len = slen - start;
	subs = (char *)malloc(sizeof(*s) * (len + 1));
	if (!subs)
		return (NULL);
	while (i < len && s[start + i] && len > 0)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
