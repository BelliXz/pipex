/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:57:07 by paradari          #+#    #+#             */
/*   Updated: 2023/10/31 15:27:03 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	sl;
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	sl = ft_strlen(s);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (i < sl)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
