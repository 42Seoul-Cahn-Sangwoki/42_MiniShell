/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_function1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:57:50 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 17:21:37 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

t_env_node	*get_node(const char *string)
{
	t_env_node	*new_node;
	char		*cp_string;
	char		*find;

	cp_string = ft_strdup(string);
	new_node = (t_env_node *)malloc(sizeof(t_env_node));
	if (!new_node)
		print_stderr("Malloc");
	new_node->next = NULL;
	new_node->prev = NULL;
	find = ft_strchr(cp_string, '=');
	if (!find)
	{
		new_node->key = ft_strdup(cp_string);
		new_node->value = NULL;
		free(cp_string);
		return (new_node);
	}
	*find = '\0';
	new_node->key = ft_strdup(cp_string);
	new_node->value = ft_strdup(find + 1);
	free(cp_string);
	return (new_node);
}

void	add_back(t_env_node **head, t_env_node *new)
{
	t_env_node	*node;

	node = (*head);
	if (!node && !new)
		return ;
	if (!node)
	{
		(*head) = new;
		return ;
	}
	while ((*head)->next != 0)
		(*head) = (*head)->next;
	(*head)->next = new;
	new->prev = *head;
	(*head) = node;
}

void	modify_env_value(t_env_node *node, const char *str)
{
	if (!node)
	{
		printf("node is absence\n");
		return ;
	}
	if (node->value != NULL)
		free(node->value);
	node->value = ft_strdup(str);
}

void	print_env_string_with_newline(t_env_node *node)
{
	if (!node)
	{
		printf("node is absence\n");
		return ;
	}
	if (node->value != NULL)
		printf("%s=%s\n", node->key, node->value);
	else
		printf("%s\n", node->key);
}

void	print_all_env(t_env_node *head)
{
	t_env_node	*search;

	search = head;
	while (search != NULL)
	{
		print_env_string_with_newline(search);
		search = search->next;
	}
}
