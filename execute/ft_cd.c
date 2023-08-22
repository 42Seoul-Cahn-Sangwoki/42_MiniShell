/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:19:11 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 15:29:25 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

char	*get_parent_free_origin(char *origin)
{
	char	*parent;
	char	*find;

	find = ft_strrchr(origin, '/');
	*find = 0;
	if (*origin == 0)
	{
		free(origin);
		return (ft_strdup("/"));
	}
	parent = ft_strdup(origin);
	free(origin);
	return (parent);
}

char	*join_path_free_origin(char *origin, char *new_path)
{
	char	*join;
	char	*join2;

	join = ft_strjoin(origin, "/");
	join2 = ft_strjoin(join, new_path);
	free(join);
	free(origin);
	return (join2);
}

int	ft_cd_no_parameter(char **parameter)
{
	char	*complete;

	complete = get_home_free_origin(NULL);
	if (chdir(complete))
	{
		free(complete);
		return (set_exit_status(1, ft_strjoin("cd: ", parameter[1]), \
			"No such file or directory"));
	}
	update_pwd();
	return (set_exit_status(0, NULL, NULL));
}

static void	find_final_path(char **split, char **complete)
{
	int	i;

	i = 0;
	while (split[i])
	{
		if (!ft_strncmp(split[i], "..", COMPARE_NUMBER))
			*complete = get_parent_free_origin(*complete);
		else if (!ft_strncmp(split[i], "~", COMPARE_NUMBER))
			*complete = get_home_free_origin(*complete);
		else if (ft_strncmp(split[i], ".", COMPARE_NUMBER))
			*complete = join_path_free_origin(*complete, split[i]);
		++i;
	}
}

int	ft_cd(char **parameter)
{
	char	*complete;
	char	**split;

	if (!parameter[1])
		return (ft_cd_no_parameter(parameter));
	if (parameter[1][0] == '/')
		complete = ft_strdup("/");
	else
		complete = get_absolute_path();
	split = ft_split(parameter[1], '/');
	if (!split)
		return (set_exit_status(1, ft_strjoin("cd: ", parameter[1]), \
				strerror(12)));
	find_final_path(split, &complete);
	free_split(&split);
	if (chdir(complete))
		return (set_exit_status(1, ft_strjoin("cd: ", parameter[1]), \
			"No such file or directory"));
	update_pwd();
	return (set_exit_status(0, NULL, NULL));
}
