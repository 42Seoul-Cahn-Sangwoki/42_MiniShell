/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:58:15 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 17:08:16 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

void    ft_pwd(char **parameter)
{
    t_env_node  *pwd;

    pwd = search_node_by_key(g_global_var.envp_head, "PWD");
    if (!pwd)
    {
        printf("no $PWD\n");
        return ;
    }
    if (pwd->value != NULL)
        printf("%s\n", pwd->value);
}