/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:26:03 by lconiau           #+#    #+#             */
/*   Updated: 2024/03/20 14:59:43 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (paths && *paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		paths++;
	}
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (cmd);
	}
	ft_free_arr(paths);
	return (NULL);
}

static void	sub_dup2(int zero, int first)
{
	dup2(zero, STDIN_FILENO);
	dup2(first, STDOUT_FILENO);
}

static void	free_cmd_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_paths && pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}

void	child(t_pipex *p, char **argv, char **envp)
{
	p->pid = fork();
	if (!p->pid)
	{
		if (p->idx == 0)
			sub_dup2(p->infile, p->pipe[1]);
		else if (p->idx == p->cmd_nmbs - 1)
			sub_dup2(p->pipe[2 * p->idx - 2], p->outfile);
		else
			sub_dup2(p->pipe[2 * p->idx - 2], p->pipe[2 * p->idx + 1]);
		if (p->infile != STDIN_FILENO)
			close(p->infile);
		if (p->outfile != STDOUT_FILENO)
			close(p->outfile);
		close_pipes(p);
		p->cmd_args = ft_split(argv[2 + p->here_doc + p->idx], ' ');
		p->cmd = get_cmd(p->cmd_paths, p->cmd_args[0]);
		free_cmd_path(p);
		if (!p->cmd)
		{
			child_free(p);
			exit(EXIT_FAILURE);
		}
		execve(p->cmd, p->cmd_args, envp);
		exit(EXIT_FAILURE);
	}
}
