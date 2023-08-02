/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:46:55 by cahn              #+#    #+#             */
/*   Updated: 2023/08/02 20:09:03 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

void	allocate_process_manage(t_process_manage *pm, int length)
{
	int	i;

	pm->child_pid_array = (int *)malloc(sizeof(int) * length);
	if (!pm->child_pid_array)
		print_stderr("Malloc");
	pm->pipe_array = (int **)malloc(sizeof(int *) * (length - 1));
	if (!pm->pipe_array)
		print_stderr("Malloc");
	i = 0;
	while (i < length - 1)
	{
		pm->pipe_array[i] = (int *)malloc(sizeof(int) * 2);
		if (!pm->pipe_array[i])
			print_stderr("Malloc");
		if (pipe(pm->pipe_array[i]) < 0)
			print_stderr("Pipe");
		++i;
	}
}

char	*find_path(char **envp)
{
	int		i;
	char	*res_path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			res_path = ft_strdup(envp[i] + 5);
			return (res_path);
		}
		++i;
	}
	non_valid_error("$PATH");
	return (NULL);
}

int	check_and_create_file_by_write(char *file_name)
{
	int	fd;

	if (!access(file_name, F_OK))
	{
		if (access(file_name, W_OK))
			return (RETURN_ERROR);
		else
			return (RETURN_NORMAL);
	}
	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 00777);
	if (fd < 0)
		print_stderr(file_name);
	close(fd);
	return (RETURN_NORMAL);
}