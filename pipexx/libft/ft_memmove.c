/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:39:35 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 23:12:08 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*tempsrc;

	temp = dest;
	tempsrc = src;
	if (!dest && !src)
		return (0);
	if (tempsrc < temp && (tempsrc + n) > temp)
	{
		temp = temp + n;
		tempsrc = tempsrc + n;
		while (n--)
			*--temp = *--tempsrc;
	}
	else
	{
		while (n--)
			*temp++ = *tempsrc++;
	}
	return (dest);
}
