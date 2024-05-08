/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:01:31 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/18 08:07:45 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static t_listlib	*create_new_element(void *content, void *(*f)(void *) \
	, void (*del)(void *))
{
	void		*new_content;
	t_listlib	*new_element;

	new_content = f(content);
	if (!new_content)
		return (NULL);
	new_element = ft_lstnew(new_content);
	if (!new_element)
	{
		del(new_content);
		return (NULL);
	}
	return (new_element);
}

t_listlib	*ft_lstmap(t_listlib *lst, void *(*f)(void*), void (*del)(void*))
{
	t_listlib	*new_list;
	t_listlib	*temp;

	if (!lst || !f || !del)
		return (NULL);
	new_list = 0;
	while (lst)
	{
		temp = create_new_element(lst->content, f, del);
		if (!temp)
		{
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
