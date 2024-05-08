/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:06:03 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/08 01:58:30 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *pointer, int value, int count)
{
	unsigned char	*temp;

	temp = pointer;
	while (count--)
	{
		*temp++ = value;
	}
	return (pointer);
}
