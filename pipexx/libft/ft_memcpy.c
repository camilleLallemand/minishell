/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:26:48 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 22:51:16 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*temp;
	const unsigned char	*tempsrc;

	temp = dest;
	tempsrc = src;
	if (!dest && !src)
		return (0);
	while (n--)
		*temp++ = *tempsrc++;
	return (dest);
}
