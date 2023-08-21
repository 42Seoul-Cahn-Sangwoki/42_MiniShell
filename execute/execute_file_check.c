/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_file_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:39:10 by cahn              #+#    #+#             */
/*   Updated: 2023/08/21 14:40:02 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

char	*find_path()
{
	t_env_node	*find;

	find = search_node_by_key(g_global_var.envp_head, "PATH");
	return (find->value);
}

void	find_execute_file(char **commands, char *path)
{
	char	**split;
	int		i;
	char	*tmp;
	char	*res;

	split = ft_split(path, ':');
	i = -1;
	while (split[++i])
	{
		tmp = ft_strjoin(split[i], "/");
		res = ft_strjoin(tmp, commands[0]);
		free(tmp);
		if (!access(res, X_OK))
		{
			free_split(&split);
			free(commands[0]);
			commands[0] = res;
			return ;
		}
		free(res);
	}
	free_split(&split);
	free(commands[0]);
	commands[0] = NULL;
}
