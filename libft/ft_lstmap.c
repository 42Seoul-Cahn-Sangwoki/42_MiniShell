/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:46:17 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/13 13:34:09 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_node;
	t_list	*new_list;
	void	*new_content;

	node = lst;
	if (node == 0 || f == 0)
		return (0);
	new_list = 0;
	while (node)
	{
		new_node = 0;
		new_content = f(node -> content);
		new_node = ft_lstnew(new_content);
		if (! new_node)
		{
			if (new_content)
				del(new_content);
			ft_lstclear(&new_list, del);
			return (0);
		}
		ft_lstadd_back(&new_list, new_node);
		node = node -> next;
	}
	return (new_list);
}
