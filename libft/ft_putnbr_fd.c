/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paradari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:51:09 by paradari          #+#    #+#             */
/*   Updated: 2023/10/31 15:28:57 by paradari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	neg;
	int		mul;
	char	num;

	mul = 1;
	neg = '-';
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, &neg, 1);
		}
		while (n / mul > 9)
			mul *= 10;
		while (mul >= 1)
		{
			num = (n / mul) + '0';
			write(fd, &num, 1);
			n = n % mul;
			mul /= 10;
		}
	}
}
