/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:26:47 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 16:37:55 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

void    execute(t_node *cmds, int length)
{
	t_process_manage	pm;
	int					i;

	// one argument, built-in
	create_heredoc_file(cmds, length);
	allocate_process_manage(&pm, length);
	i = 0;
	while (i < length)
	{
		pm.child_pid_array[i] = fork();
		if (pm.child_pid_array[i] < 0)
			print_stderr("Fork");
		else if (!pm.child_pid_array[i])
			token_processing(cmds + i, pm.pipe_array[i], i, length);
		++i;
	}
	parent_processing(&pm, cmds, length);
}