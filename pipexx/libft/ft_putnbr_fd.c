/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:37:07 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/18 08:37:16 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	c[50];
	long	a;

	nb = n;
	a = 0;
	if (0 == nb)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	while (nb)
	{
		c[a++] = (nb % 10) + '0';
		nb /= 10;
	}
	while (a > 0)
	{
		write(fd, &c[--a], 1);
	}
}
