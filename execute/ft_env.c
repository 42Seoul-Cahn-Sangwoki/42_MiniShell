/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:58:28 by cahn              #+#    #+#             */
/*   Updated: 2023/08/16 20:34:31 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static void    print_env_string_with_newline_have_value(t_env_node *node)
{
    if (!node)
    {
        printf("node is absence\n");
        return ;
    }
    if (node->value != NULL)
        printf("%s=%s\n", node->key, node->value);
}

// 모든 env 출력
static void    print_all_env_have_value(t_env_node *head)
{
    t_env_node  *search;

    search = head;
    while (search != NULL)
    {
        print_env_string_with_newline(search);
        search = search->next;
    }
}

void    ft_env(char **parameter) // value있는것만 출력
{

    if (parameter[1])
    {
        printf("ft_env needs no arguments or option\n");
        return ;
    }
    print_all_env_have_value(g_global_var.envp_head);
}