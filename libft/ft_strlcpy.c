/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:01:20 by paradari          #+#    #+#             */
/*   Updated: 2023/10/30 15:27:35 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && *(src + i))
		{
			*(dest + i) = *(src + i);
			i++;
		}
		*(dest + i) = 0;
	}
	return (ft_strlen(src));
}
