/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:47:17 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 23:12:23 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	char	temp;

	temp = (char) searchedChar;
	while (*string != '\0')
	{
		if (*string == temp)
			return ((char *)string);
		string++;
	}
	if (temp == '\0')
		return ((char *)string);
	return (NULL);
}
