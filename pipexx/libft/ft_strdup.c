/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:16:42 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 22:57:32 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	size_t	lensrc;

	lensrc = ft_strlen((char *)src) + 1;
	temp = malloc(lensrc * sizeof(char));
	if (!temp)
		return (NULL);
	ft_strlcpy(temp, src, lensrc);
	return (temp);
}
