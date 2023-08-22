/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_file_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:39:10 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 14:29:36 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

char	*find_path(void)
{
	t_env_node	*find;

	find = search_node_by_key(g_global_var.envp_head, "PATH");
	return (ft_strdup(find->value));
}

int	find_execute_file(char **commands, char *path)
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
			return (1);
		}
		free(res);
	}
	free_split(&split);
	return (0);
}

int	is_valid_execute_file(char	*commands, char *path)
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
		res = ft_strjoin(tmp, commands);
		free(tmp);
		if (!access(res, X_OK))
		{
			free(res);
			free_split(&split);
			return (1);
		}
		free(res);
	}
	free_split(&split);
	return (0);
}
