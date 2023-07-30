/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:26:21 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/12 14:48:50 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = (*lst);
	if (! node && ! new)
		return ;
	if (! node)
	{
		(*lst) = new;
		return ;
	}
	while ((*lst)->next != 0)
		(*lst) = (*lst)->next;
	(*lst)->next = new;
	(*lst) = node;
}
