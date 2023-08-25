/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_file_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:39:10 by cahn              #+#    #+#             */
/*   Updated: 2023/08/25 16:19:27 by cahn             ###   ########.fr       */
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

	if (!commands[0][0])
		return (0);
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

int	is_valid_execute_file(char *commands, char *path)
{
	char	**split;
	int		i;
	char	*tmp;
	char	*res;

	if (!commands[0])
		return (0);
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

int	is_built_in(char *command)
{
	if (!ft_strncmp(command, "cd", COMPARE_NUMBER))
		return (1);
	if (!ft_strncmp(command, "echo", COMPARE_NUMBER))
		return (1);
	if (!ft_strncmp(command, "pwd", COMPARE_NUMBER))
		return (1);
	if (!ft_strncmp(command, "export", COMPARE_NUMBER))
		return (1);
	if (!ft_strncmp(command, "unset", COMPARE_NUMBER))
		return (1);
	if (!ft_strncmp(command, "env", COMPARE_NUMBER))
		return (1);
	if (!ft_strncmp(command, "exit", COMPARE_NUMBER))
		return (1);
	return (0);
}

int	execute_built_in(char *command, char **parameter, int one)
{
	if (!ft_strncmp(command, "cd", COMPARE_NUMBER))
		return (ft_cd(parameter));
	if (!ft_strncmp(command, "echo", COMPARE_NUMBER))
		return (ft_echo(parameter));
	if (!ft_strncmp(command, "pwd", COMPARE_NUMBER))
		return (ft_pwd(parameter));
	if (!ft_strncmp(command, "export", COMPARE_NUMBER))
		return (ft_export(parameter));
	if (!ft_strncmp(command, "unset", COMPARE_NUMBER))
		return (ft_unset(parameter));
	if (!ft_strncmp(command, "env", COMPARE_NUMBER))
		return (ft_env(parameter));
	if (!ft_strncmp(command, "exit", COMPARE_NUMBER))
		return (ft_exit(parameter, one));
	return (0);
}
