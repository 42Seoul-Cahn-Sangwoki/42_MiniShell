/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:58:15 by cahn              #+#    #+#             */
/*   Updated: 2023/08/21 19:56:08 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

int ft_pwd(char **parameter)
{
    t_env_node  *pwd;

    (void)parameter;
    pwd = search_node_by_key(g_global_var.envp_head, "PWD");
    if (!pwd)
        return (set_exit_status(0, NULL, NULL));
    if (pwd->value != NULL)
        printf("%s\n", pwd->value);
    return (set_exit_status(0, NULL, NULL));
}