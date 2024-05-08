/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:17:15 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/08 01:23:50 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *fullString, const char *substr, size_t len)
{
	size_t	i;
	int		j;

	if (*substr == '\0')
		return ((char *)fullString);
	i = 0;
	while (fullString[i] != '\0' && i < len)
	{
		if (fullString[i] == substr[0])
		{
			j = 0;
			while (substr[j] && fullString[i + j] && i + j < len
				&& fullString[i + j] == substr[j])
				j++;
			if (substr[j] == '\0')
				return ((char *)fullString + i);
		}
		i++;
	}
	return (0);
}
