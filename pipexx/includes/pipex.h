/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <lconiau@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:43:54 by lconiau           #+#    #+#             */
/*   Updated: 2024/03/15 22:58:16 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx;
	int		infile_ok;
	int		outfile_ok;
}			t_pipex;

void	ft_free_arr(char **s);
void	close_pipes(t_pipex *pipex);
void	child(t_pipex *pipex, char **argv, char **envp);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	pipe_free(t_pipex *pipex);
void	find_path(char **envp, t_pipex *pipex);
void	get_infile(char **argv, t_pipex *pipex);
void	get_outfile(char *argv, t_pipex *pipex);
int		args_in(char *arg, t_pipex *pipex);
void	here_doc(char *argv, t_pipex *pipex);
void	msg_error(char *err);
void	msg_pipe(char *arg);
int		msg(char *err);

#endif