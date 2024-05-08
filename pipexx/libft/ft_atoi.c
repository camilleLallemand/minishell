/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:12:45 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/18 08:08:03 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *string)
{
	long	i;
	long	temp;
	int		sign;

	i = 0;
	temp = 0;
	sign = 1;
	while ((string[i] >= 9 && string[i] <= 13) || string[i] == ' ')
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		if ((temp * 10 + (string[i] - '0') < temp))
			return (-(sign == 1));
		temp = temp * 10 + (string[i] - 48);
		i++;
	}
	return ((int)(temp * sign));
}
