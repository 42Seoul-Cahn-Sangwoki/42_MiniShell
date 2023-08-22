/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:26:47 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 15:31:18 by cahn             ###   ########.fr       */
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
}

int	one_argument_processing(t_node *cmds)
{
	char	*path;

	if (is_built_in(cmds[0].commands[0]))
	{
		one_built_in_processing(cmds);
		return (1);
	}
	path = find_path();
	if (access(cmds->commands[0], X_OK))
	{
		if (!is_valid_execute_file(cmds->commands[0], path))
		{
			free(path);
			return (set_exit_status(127, ft_strdup(cmds->commands[0]), \
			"command not found"));
		}
	}
	free(path);
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

int	execute_built_in(char *command, char **parameter)
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
		return (ft_exit(parameter));
	return (0);
}

void	execute(t_node *cmds, int length)
{
	t_process_manage	pm;
	int					i;

	create_heredoc_file(cmds, length);
	if (length == 1)
	{
		if (one_argument_processing(cmds))
		{
			delete_tmp_file(cmds, 1);
			return ;
		}
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
