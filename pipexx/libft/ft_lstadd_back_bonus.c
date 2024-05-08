/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:03:20 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 23:13:30 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_listlib **lst, t_listlib *new)
{
	t_listlib	*temp;

	if (lst)
	{
		if (*lst)
		{
			temp = *lst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*lst = new;
	}
}
