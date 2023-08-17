/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:44:15 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 17:15:10 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

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

int	return_input_fd(t_file_info *head)
{
	if (head == NULL)
		return (-1);
	while (head->next != NULL)
	{
		if (head->write_mode == READ && access(head->file_name, R_OK))
			print_stderr(head->file_name);
		head = head->next;
	}
	if (head->write_mode == HERE_DOC)
		return (open(head->file_name, O_RDONLY));
	if (head->write_mode == READ && access(head->file_name, R_OK))
		print_stderr(head->file_name);
	return (open(head->file_name, O_RDONLY));
}

int	return_output_fd(t_file_info *head)
{
	if (head == NULL)
		return (-1);
	while (head->next != NULL)
	{
		if (check_and_create_file_by_write(head->file_name))
			print_stderr(head->file_name);
		head = head->next;
	}
	if (check_and_create_file_by_write(head->file_name))
		print_stderr(head->file_name);
	if (head->write_mode == WRITE_NEW)
		return (open(head->file_name, O_WRONLY | O_CREAT | O_TRUNC, 00777));
	return (open(head->file_name, O_WRONLY | O_CREAT | O_APPEND, 00777));
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

void	execute_built_in(char *command, char **parameter)
{
	if (!ft_strncmp(command, "cd", COMPARE_NUMBER))
		ft_cd(parameter[0]);
	if (!ft_strncmp(command, "echo", COMPARE_NUMBER))
		ft_echo(parameter);
	if (!ft_strncmp(command, "pwd", COMPARE_NUMBER))
		ft_pwd(parameter);
	if (!ft_strncmp(command, "export", COMPARE_NUMBER))
		ft_export(parameter);
	if (!ft_strncmp(command, "unset", COMPARE_NUMBER))
		ft_unset(parameter);
	if (!ft_strncmp(command, "env", COMPARE_NUMBER))
		ft_env(parameter);
	if (!ft_strncmp(command, "exit", COMPARE_NUMBER))
		ft_exit(parameter);
}

int	token_processing(t_node *token, int *pipe, int index, int length)
{
	int		input_fd;
	int		output_fd;
	char	*path;
	char	**argu_envp;

	input_fd = return_input_fd(token->infile_head);
	output_fd = return_output_fd(token->outfile_head);
	if (input_fd != -1)
		dup2(input_fd, 0);
	else
		dup2(pipe[0], 0);
	if (output_fd != -1)
		dup2(output_fd, 1);
	else if (index < length - 1)
		dup2(pipe[1], 1);
	if (is_built_in(token->commands[0]))
	{
		execute_built_in(token->commands[0], token->commands);
		exit(g_global_var.exit);
	}
	path = find_path();
	if (access(token->commands[0], X_OK))	
		find_execute_file(token->commands, path);
	if (token->commands[0] == NULL)
		print_stderr("Commands not found");
	argu_envp = make_origin_form_envp(g_global_var.envp_head);
	execve(token->commands[0], token->commands, argu_envp);
	print_stderr("execve");
}