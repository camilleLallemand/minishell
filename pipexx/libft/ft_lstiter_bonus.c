/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:59:46 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 23:00:36 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_listlib *lst, void (*f)(void*))
{
	if (!lst || (!f))
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
