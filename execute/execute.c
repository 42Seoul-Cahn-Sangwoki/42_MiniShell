/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:26:47 by cahn              #+#    #+#             */
/*   Updated: 2023/08/21 20:14:51 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

void	one_built_in_processing(t_node *cmds)
{
	int		input_fd;
	int		output_fd;

	input_fd = return_input_fd(cmds[0].infile_head);
	output_fd = return_output_fd(cmds[0].outfile_head);
	if (input_fd != -1)
		dup2(input_fd, 0);
	if (output_fd != -1)
		dup2(output_fd, 1);
	execute_built_in(cmds[0].commands[0], cmds[0].commands);
	delete_tmp_file(cmds, 1);
}


void    execute(t_node *cmds, int length)
{
	t_process_manage	pm;
	int					i;

	create_heredoc_file(cmds, length);
	if (length == 1 && is_built_in(cmds[0].commands[0]))
	{
		one_built_in_processing(cmds);
		return ;
	}
	allocate_process_manage(&pm, length);
	i = 0;
	while (i < length)
	{
		pm.child_pid_array[i] = fork();
		if (pm.child_pid_array[i] < 0)
			print_stderr("Fork");
		else if (!pm.child_pid_array[i])
			token_processing(cmds + i, pm.pipe_array, i, length);
		++i;
	}
	parent_processing(&pm, cmds, length);
}