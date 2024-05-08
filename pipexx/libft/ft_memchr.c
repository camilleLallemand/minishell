/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:08:59 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/18 08:23:17 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	const unsigned char	*temp;
	size_t				i;

	i = 0;
	temp = memoryBlock;
	while (i < size)
	{
		if (temp[i] == (unsigned char) searchedChar)
			return ((void *)temp + i);
		i++;
	}
	return (NULL);
}
