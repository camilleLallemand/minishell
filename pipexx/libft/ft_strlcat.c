/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:52:54 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 22:56:35 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	sizesrc;
	size_t	sizedst;
	size_t	i;

	i = 0;
	sizesrc = ft_strlen((char *) src);
	sizedst = ft_strlen(dst);
	if (size <= sizedst)
		return (sizesrc + size);
	while (i < size - sizedst - 1 && src[i])
	{
		dst[sizedst + i] = src[i];
		i++;
	}
	dst[sizedst + i] = '\0';
	return (sizesrc + sizedst);
}
