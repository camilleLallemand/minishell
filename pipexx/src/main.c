/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:31:27 by lconiau           #+#    #+#             */
/*   Updated: 2024/03/21 14:16:39 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	creat_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_nmbs - 1)
	{
		if (pipe(pipex->pipe + 2 * i) < 0)
			parent_free(pipex);
		i++;
	}
}

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < (pipex->pipe_nmbs))
	{
		close(pipex->pipe[i]);
		i++;
	}
}

static void	check_exec(t_pipex *pipex, char **argv, char **env)
{
	while (pipex->idx < pipex->cmd_nmbs)
	{
		if (pipex->idx == 0 && pipex->infile_ok == 0)
		{
			pipex->idx++;
			continue ;
		}else
			child(pipex, argv, env);
		pipex->idx++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < args_in(argv[1], &pipex))
		return (msg(ERR_INPUT));
	get_infile(argv, &pipex);
	get_outfile(argv[argc - 1], &pipex);
	pipex.cmd_nmbs = argc - 3 - pipex.here_doc;
	pipex.pipe_nmbs = 2 * (pipex.cmd_nmbs - 1);
	pipex.pipe = (int *)malloc(sizeof(int) * pipex.pipe_nmbs);
	if (!pipex.pipe)
		msg_error(ERR_PIPE);
	find_path(envp, &pipex);
	creat_pipes(&pipex);
	pipex.idx = 0;
	check_exec(&pipex, argv, envp);
	close_pipes(&pipex);
	while (wait(NULL) > 0)
	{
	}
	parent_free(&pipex);
	return (0);
}
