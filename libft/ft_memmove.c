/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:57:34 by paradari          #+#    #+#             */
/*   Updated: 2023/11/02 16:30:32 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	if (dest != 0 || src != 0)
	{
		d = (char *)dest;
		s = (char *)src;
		if (d > s)
		{
			i = len;
			while (i-- > 0)
				d[i] = s[i];
		}
		else
		{
			i = 0;
			while (i < len)
			{
				d[i] = s[i];
				i++;
			}
		}
	}
	return (dest);
}
