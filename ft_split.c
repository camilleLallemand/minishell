#include "minishell.h"

static size_t	count_word(char const *s1, char c)
{
	size_t	i;
	int		res;
	int		count;

	count = 0;
	i = 0;
	res = 1;
	while (s1[i])
	{
		if (s1[i] == c && res == 0)
			res = 1;
		if (s1[i] != c && res == 1)
		{
			res = 0;
			count ++;
		}
		i++;
	}
	return (count);
}

static size_t	is_word(char const *s1, char c, size_t i, int role)
{
	if (role == 1)
	{
		while (s1[i] != c && s1[i])
			i++;
		return (i);
	}
	else
	{
		while (s1[i] == c)
			i++;
		return (i);
	}
}

static int	free_tab(char **tab, int i)
{
	if (!tab[i])
	{
		while (i >= 0)
		{
			free(tab[i]);
			i--;
		}
		free(tab);
		return (0);
	}
	return (1);
}

static char	*create_word(char const *s1, int a, int b)
{
	size_t	i;
	char	*ns;

	i = 0;
	ns = malloc(sizeof(char) * (b - a + 1));
	if (!ns)
		return ((void *)0);
	while (a < b)
	{
		ns[i] = s1[a];
		i++;
		a++;
	}
	ns[i] = '\0';
	return (ns);
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	size_t		i;
	size_t		pos;
	size_t		wordnbr;

	i = 0;
	pos = 0;
	wordnbr = count_word(s, c);
	tab = malloc(sizeof (char *) * (wordnbr + 1));
	if (!tab)
		return ((void *)0);
	while (i < wordnbr)
	{
		pos = is_word(s, c, pos, 0);
		tab[i] = create_word(s, pos, is_word(s, c, pos, 1));
		pos = is_word(s, c, pos, 1);
		if (free_tab(tab, i) == 0)
			return ((void *)0);
		i++;
	}
	tab[i] = ((void *)0);
	return (tab);
}
