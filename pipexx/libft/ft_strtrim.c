/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:00:40 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/18 08:07:11 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_search(const char *s1, char c)
{
	while (*s1 != '\0')
	{
		if (*s1 == c)
			return (1);
		s1++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*start;
	char	*end;
	char	*temp;
	size_t	full_size;

	if (s1 == NULL)
		return (NULL);
	start = (char *)s1;
	end = (char *)s1 + ft_strlen((char *)s1) - 1;
	while (*start && is_search(set, *start))
		start++;
	if (*start == 0)
		return (ft_strdup(""));
	while (end > start && is_search(set, *end))
		end--;
	full_size = end - start + 1;
	temp = (char *)malloc(full_size + 1);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, start, full_size);
	temp[full_size] = '\0';
	return (temp);
}
