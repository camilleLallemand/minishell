/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:05:10 by lconiau           #+#    #+#             */
/*   Updated: 2024/03/06 19:34:38 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	free_malloc(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (1);
}

static char	*malloc_word(const char *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (i <= 0)
		return ((void *)0);
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return ((void *)0);
	ft_strlcpy(word, s, i + 1);
	return (word);
}

static int	skip_word(char *s, char c, int check)
{
	int	i;

	i = 0;
	if (check)
		while (s[i] && s[i] != c)
			i++;
	else
		while (s[i] && s[i] == c)
			i++;
	return (i);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	size_t	words;
	size_t	i;

	if (!s)
		return ((void *)0);
	words = count_words(s, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return ((void *)0);
	i = 0;
	while (i < words)
	{
		s += skip_word(s, c, 0);
		if (s)
		{
			split[i] = malloc_word(s, c);
			if (!split[i] && free_malloc(split, i))
				return ((void *)0);
			i++;
		}
		s += skip_word(s, c, 1);
	}
	split[i] = NULL;
	return (split);
}
