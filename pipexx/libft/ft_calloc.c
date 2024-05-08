/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:42:23 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 23:06:57 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t	all;
	void	*temp;

	all = elementCount * elementSize;
	if (all && (all / elementCount) != elementSize)
		return (0);
	temp = malloc(all);
	if (!temp)
		return (0);
	ft_memset(temp, 0, all);
	return (temp);
}
