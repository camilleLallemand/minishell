/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:08:52 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 23:11:27 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*temp;
	int		size;
	long	nb;

	nb = n;
	size = ft_len(n);
	temp = (char *)malloc(size + 1);
	if (!temp)
		return (NULL);
	temp[size] = '\0';
	if (nb < 0)
	{
		temp[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		temp[0] = '0';
	while (nb > 0)
	{
		temp[--size] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (temp);
}
