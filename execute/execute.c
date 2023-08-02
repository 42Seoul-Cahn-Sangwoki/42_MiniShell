/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:26:47 by cahn              #+#    #+#             */
/*   Updated: 2023/08/02 20:20:59 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

char **g_envp;

void	parent_processing(t_process_manage *pm, int length)
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		close(pm->pipe_array[i][0]);
		close(pm->pipe_array[i][1]);
		++i;
	}
	i = 0;
	while (i < length)
	{
		waitpid(pm->child_pid_array[i], NULL, WNOHANG);
		++i;
	}
}

int	return_redirection_fd(t_file_info *head)
{
	if (head == NULL)
		return (-1);
	while (head->next != NULL)
	{
		if (head->write_mode == READ && access(head->file_name, R_OK))
			print_stderr(head->file_name);
		if (check_and_create_file_by_write(head->file_name))
			print_stderr(head->file_name);
		head = head->next;
	}
	if (head->write_mode == READ && access(head->file_name, R_OK))
		print_stderr(head->file_name);
	if (check_and_create_file_by_write(head->file_name))
		print_stderr(head->file_name);
	if (head->write_mode == READ)
		return (open(head->file_name, O_RDONLY));
	else if (head->write_mode == WRITE_NEW)
		return (open(head->file_name, O_WRONLY | O_CREAT | O_TRUNC, 00777));
	return (open(head->file_name, O_WRONLY | O_CREAT | O_APPEND, 00777));
}

void	find_execute_file(char **commands, char *path)
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
			return ;
		}
		free(res);
	}
	free_split(&split);
	free(commands[0]);
	commands[0] = NULL;
}

int	token_processing(t_node *token, int *pipe, int index, int length)
{
	int		input_fd;
	int		output_fd;
	char	*path;

	input_fd = return_redirection_fd(token->infile_head);
	output_fd = return_redirection_fd(token->outfile_head);
	if (input_fd != -1)
		dup2(input_fd, 0);
	else
		dup2(pipe[0], 0);
	if (output_fd != -1)
		dup2(output_fd, 1);
	else if (index < length - 1)
		dup2(pipe[1], 1);
	path = find_path(g_envp);
	if (access(token->commands[0], X_OK))	
		find_execute_file(token->commands, path);
	if (token->commands[0] == NULL)
		print_stderr("Commands not found");
	free(path);
	execve(token->commands[0], token->commands, g_envp);
}

void    execute(t_node *cmds, int length)
{
	t_process_manage	pm;
	int					i;

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
	parent_processing(&pm, length);
}