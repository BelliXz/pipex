/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:35:42 by paradari          #+#    #+#             */
/*   Updated: 2023/08/27 20:25:33 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destp;
	const char	*srcp;

	if (!dest && !src)
	{
		return (NULL);
	}
	destp = (char *)dest;
	srcp = src;
	while (n-- > 0)
	{
		*destp = *srcp;
		destp++;
		srcp++;
	}
	return (dest);
}
