#include "minishell.h"

#define MAX_COMMAND_LENGTH 1024
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

int fill_token(char ***token, char *input, int size) {
    char **s;
    int x = 0;
    int y = 0;
    int z = 0;

    s = split(input);
    if (!s)
        return -1;

    *token = malloc(sizeof(char ***) * (size+3));
    if (!(*token)) {
        free(s);
        return -1;
    }

    while (s[x] != NULL) {
        if (s[x] && s[x][0] != '|') {
            (*token)[z] = (s[x]);
            if (!(*token)[z]) {
                for (int i = 0; i < z; i++)
                    free((*token)[i]);
                free(*token);
                free(s);
                return -1;
            }
            z++;
        } else {
            x++;

        }
        x++;
    }

    (*token)[z] = NULL;

    free(s);

    return 1;
}


/*
int main() {
    char input[MAX_COMMAND_LENGTH];
    char	***token;
    char 	**cmd;
    int	nbr_tok;
    while(1) {
        printf("minishell> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Supprimer le retour à la ligne
	nbr_tok = how_cmd(input);
	if (nbr_tok > 0)
		token = malloc(sizeof(char *** ) * (nbr_tok + 1));
	if (!token)
		return -1;
	fill_token(token, input, nbr_tok);

	int i;
	i = 0;
	while(token[0][i] != NULL)
	{
		printf("%s\n",token[0][i]);
		i++;
	}
	free(token);

    }

    return 0;
}*/
