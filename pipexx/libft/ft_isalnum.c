/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconiau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 22:50:38 by lconiau           #+#    #+#             */
/*   Updated: 2023/11/08 01:15:42 by lconiau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalnum(int character)
{
	if ((character >= 48 && character <= 57)
		|| (character >= 65 && character <= 90)
		|| (character >= 97 && character <= 122))
	{
		return (1);
	}
	else
		return (0);
}