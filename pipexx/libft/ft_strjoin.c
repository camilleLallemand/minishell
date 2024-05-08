/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:33:15 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/18 08:36:23 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	temp = malloc(lens1 + lens2 + 1);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, s1, lens1);
	ft_memcpy(temp + lens1, s2, lens2);
	*(temp + lens1 + lens2) = '\0';
	return (temp);
}
