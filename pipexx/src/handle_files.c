/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:28:19 by lconiau           #+#    #+#             */
/*   Updated: 2024/03/15 19:58:06 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	find_path(char **envp, t_pipex *pipex)
{
	if (envp == NULL)
		pipex->env_path = NULL;
	while (envp && *envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (envp && *envp)
	{
		pipex->env_path = *envp + 5;
		pipex->cmd_paths = ft_split(pipex->env_path, ':');
		return ;
	}
	pipex->env_path = NULL;
	pipex->cmd_paths = NULL;
	return ;
}

void	get_infile(char **argv, t_pipex *pipex)
{
	pipex->infile_ok = 1;
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
		{
			pipex->infile_ok = 0;
			pipex->infile = open("/dev/null", O_RDONLY);
			msg_error(ERR_INFILE);
		}
	}
}

void	get_outfile(char *argv, t_pipex *pipex)
{
	pipex->outfile = 1;
	if (pipex->here_doc)
		pipex->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		pipex->outfile = open(argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile < 0)
	{
		pipex->outfile_ok = 0;
		msg_error(ERR_OUTFILE);
	}
}
