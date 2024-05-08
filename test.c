#include "minishell.h"

#define MAX_COMMAND_LENGTH 1024

typedef struct s_shell
{
	int nbr_cmd;
	char ***token;
	int **statut;
}	t_shell;



int is_space(char c)
{
	if (c == 32 || c == 9 || c == 10 || c == 124)
		return 1;
	else
		return 0;
}



int how_cmd(char *s)
{
	int i;
	int tok;
	int ext;

	i = 0;
	tok = 0;
	ext = 0;
	if (!s)
		return 0;
	while(s[i])
	{
		if (ext == 0 && (s[i] != '|' && is_space(s[i]) != 1))
		{
			ext = 1;
			if (s[i] != '|')
				tok++;
		}
		if (s[i] == '|' && ext == 1)
			ext = 0;
		i++;
	}
	return tok;
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

int count_cmd(char **s)
{
	int	i;
	int	tt;

	i = 0;
	tt = 1;
	while(s[i])
	{
		if (s[i][0] == '|')
			tt++;
		i++;
	}
	return (tt);
}

int split_cnt(char **s)
{
	int i;

	i = 0;
	while(s[i] != NULL)
		i++;
	return i;
}

int token_filler(char **s, char ***token)
{
	int i;
	int j;
	int k;
	int nbr_tok;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (-1);
	nbr_tok = count_cmd(s);
	token = malloc(sizeof(char ***) * (nbr_tok + 2));
	if (!token)
		return (-1);
	while (s[i] != NULL)
	{
		if (s[i][0] == '|')
		{
			//token[k][j] = NULL;
			k++;
			j = 0;
		}
		token[k][j] = malloc(sizeof(char **) * (split_cnt(s)));
		token[k][j] = s[i];
		write(1,"chevre",6);
		j++;
		i++;
	}
	//token[k][j] = NULL;
	token[k+1] = NULL;
	return 1;

}


void free_token(char ***token)
{
	int i = 0;
	int k = 0;
	while (token[k] != NULL)
	{
		while (token[k][i] != NULL)
		{
			free(token[k][i]);
			i++;
		}
		free(token[k]);
		k++;
		i = 0;
	}
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char	***token;
    char 	**cmd;
    char	**s;
    int	nbr_tok;
    while(1) {
        printf("minishell> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
	s = ft_split(input, 32);
	if (!s)
		return -1;
	token_filler(s,token);
	free_token(token);
    }
    return 0;
}

