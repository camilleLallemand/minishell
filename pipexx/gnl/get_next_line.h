/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:11:43 by lconiau           #+#    #+#             */
/*   Updated: 2023/12/15 02:23:47 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}		t_list;

int		get_next_line(int fd, char **buf);
t_list	*ft_get_last(t_list *stash);
void	free_stash(t_list *stash);
void	extract_line(t_list *stash, char **line);
void	read_and_stack(int fd, t_list **stash);
int		found_newline(t_list *stash);
void	generate_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
void	add_to_stash(t_list **stash, char *buf, int readed);

#endif
