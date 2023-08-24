/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:42:52 by cahn              #+#    #+#             */
/*   Updated: 2023/08/24 18:19:44 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

int	update_pwd(void)
{
	char		*cur_path;
	t_env_node	*pwd;
	t_env_node	*old_pwd;

	cur_path = (char *)malloc(PATH_MAX + 1);
	if (!cur_path)
		return (set_exit_status(12, NULL, NULL));
	if (!getcwd(cur_path, PATH_MAX))
		return (set_exit_status(34, cur_path, "impossible getcwd"));
	pwd = search_node_by_key(g_global_var.envp_head, "PWD");
	old_pwd = search_node_by_key(g_global_var.envp_head, "OLDPWD");
	if (!pwd)
		return (set_exit_status(1, ft_strdup("cd"), "no $PWD"));
	if (!old_pwd)
		return (set_exit_status(1, ft_strdup("cd"), "no $OLDPWD"));
	modify_env_value(old_pwd, pwd->value);
	modify_env_value(pwd, cur_path);
	free(cur_path);
	return (0);
}

char	*get_absolute_path(void)
{
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
	if (!buffer)
	{
		g_global_var.exit = 12;
		return (NULL);
	}
	if (!getcwd(buffer, PATH_MAX + 1))
	{
		g_global_var.exit = 34;
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_home_free_origin(char *origin)
{
	t_env_node	*find;

	find = search_node_by_key(g_global_var.envp_head, "HOME");
	if (!find)
	{
		printf("No $home : no implement\n");
		return (origin);
	}
	if (origin != NULL)
		free(origin);
	return (ft_strdup(find->value));
}
