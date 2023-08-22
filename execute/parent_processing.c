/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:42:27 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 16:19:23 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"
#include "../signal/signal.h"

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

void	delete_tmp_file(t_node *cmds, int length)
{
	int			i;
	t_file_info	*find;

	i = 0;
	while (i < length)
	{
		find = cmds->infile_head;
		while (find != NULL)
		{
			if (find->write_mode == HERE_DOC)
				if (unlink(find->file_name))
					print_stderr(find->file_name);
		}
		++i;
	}
}

void	close_all_pipe(int **pipe_array, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		close(pipe_array[i][0]);
		close(pipe_array[i][1]);
		free(pipe_array[i]);
		++i;
	}
}

void	parent_processing(t_process_manage *pm, t_node *cmds, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		close(pm->pipe_array[i][0]);
		close(pm->pipe_array[i][1]);
		free(pm->pipe_array[i]);
		++i;
	}
	free(pm->pipe_array);
	execute_parent_signal();
	i = 0;
	while (i < length)
	{
		if (!ft_strncmp(cmds[i].commands[0], "./minishell", 11))
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
		}
		waitpid(pm->child_pid_array[i], NULL, 0);
		++i;
	}
	free(pm->child_pid_array);
	delete_tmp_file(cmds, length);
}
