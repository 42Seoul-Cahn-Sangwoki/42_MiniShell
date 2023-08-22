/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_function3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:59:33 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 17:00:12 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	free_env_node(t_env_node *node)
{
	if (node->key)
		free(node->key);
	if (node->value)
		free(node->value);
	free(node);
}

void	free_env_list(t_env_node **head)
{
	t_env_node	*tmp;
	t_env_node	*next;

	if (!(head) || !(*head))
		return ;
	tmp = *head;
	while (tmp != NULL)
	{
		next = tmp->next;
		free_env_node(tmp);
		tmp = next;
	}
	*head = NULL;
}
