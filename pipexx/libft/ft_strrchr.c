/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:55:40 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/08 01:45:55 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	char	temp;
	char	*last;

	last = NULL;
	temp = (char) searchedChar;
	if (temp == '\0')
		return ((char *)string + ft_strlen((char *)string));
	while (*string)
	{
		if (*string == temp)
			last = (char *)string;
		string++;
	}
	return (last);
}
