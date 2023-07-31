/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:26:47 by cahn              #+#    #+#             */
/*   Updated: 2023/07/31 18:22:55 by cahn             ###   ########.fr       */
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

int	token_processing(t_node *token)
{
	
}

void    execute(t_node *cmds, int length)
{
	int			i;
	int			*child_pid_array;
	int			**my_pipe;

	i = 0;
	child_pid_array = (int *)malloc(sizeof(int) * length);
	if (!child_pid_array)
		print_stderr("Malloc");
	my_pipe = (int **)malloc(sizeof(int *) * length);
	if (!my_pipe)
		print_stderr("Malloc");
	
	while (i < length)
	{

		child_pid_array[i] = fork();
		if (child_pid_array[i] == -1)
			print_stderr("fork");
		//
	}
}