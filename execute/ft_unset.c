/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:58:21 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 13:32:58 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static int valid_string(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isalnum(str[i]) && str[i] != '_')
            return (0);
        ++i;
    }
    return (1);
}

void    ft_unset(char **parameter)
{
    int         i;
    t_env_node  *find;

    if (!parameter[1])
        return ;
    i = 1;
    while (parameter[i])
    {
        if (!(ft_isalpha(parameter[i][0]) || parameter[i][0] == '_') || !valid_string(parameter[i])) // 인자형식
            printf("%s : not a valid identifier\n", parameter[i]);
        else
        {
            find = search_node_by_key(g_global_var.envp_head, parameter[i]);
            if (find)
                delete_node(&g_global_var.envp_head, find);
        }
        ++i;
    }
}