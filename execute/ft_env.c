/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:58:28 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 14:55:09 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static void	print_env_string_with_newline_have_value(t_env_node *node)
{
	if (!node)
	{
		printf("node is absence\n");
		return ;
	}
	if (node->value != NULL)
		printf("%s=%s\n", node->key, node->value);
}

static void	print_all_env_have_value(t_env_node *head)
{
	t_env_node	*search;

	search = head;
	while (search != NULL)
	{
		print_env_string_with_newline_have_value(search);
		search = search->next;
	}
}

int	ft_env(char **parameter)
{
	if (parameter[1])
		return (set_exit_status(1, ft_strjoin("env: ", parameter[1]), \
			"No such file or directory"));
	print_all_env_have_value(g_global_var.envp_head);
	return (set_exit_status(0, NULL, NULL));
}
