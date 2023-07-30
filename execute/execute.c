/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:26:47 by cahn              #+#    #+#             */
/*   Updated: 2023/07/30 17:47:11 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"

char **g_envp;

char	*find_path()
{
	int		i;
	char	*res_path;

	i = 0;
	while (g_envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", g_envp[i], 5) == 0)
		{
			res_path = ft_strdup(g_envp[i] + 5);
			return (res_path);
		}
		++i;
	}
	return (NULL);
}

void    execute(t_node *cmds, int length)
{
    char    *path_list;
    int     i;

    path_list = find_path();
    if (path_list == NULL)
        non_valid_error("PATH");
    
}