/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:26:39 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/13 13:24:55 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (! lst)
		return ;
	while ((*lst) != 0)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		if (tmp -> content)
		{
			del(tmp -> content);
			if (! (tmp -> content))
				free(tmp -> content);
		}
		free(tmp);
	}
	(*lst) = 0;
}
