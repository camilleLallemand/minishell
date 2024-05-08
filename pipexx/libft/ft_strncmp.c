/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:01:39 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/17 23:12:44 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(const char *first, const char *second, int lenght)
{
	while (lenght--)
	{
		if (*first != *second)
			return ((unsigned char)*first - (unsigned char)*second);
		if (*first == '\0')
			break ;
		first++;
		second++;
	}
	return (0);
}
