/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:54:17 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/25 20:48:39 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

char	*file_name_quote(char *file_name, int *error)
{
	char	**tmp;
	char	*name;
	char	*env_var;

	tmp = ft_split_group(file_name, TRUE, TRUE);
	handle_quote(tmp, FALSE);
	name = ft_strdup(tmp[0]);
	if (name[0] == '$')
	{
		env_var = find_env(ft_strdup(&name[1]));
		if (env_var[0] == 0)
		{
			*error = 1;
			free(env_var);
		}
		else
		{
			free(name);
			name = env_var;
		}
	}
	free_split(&tmp);
	return (name);
}

t_file_info	*get_info(char *file_name, int write_mode)
{
	t_file_info	*info;
	int			error;

	if (file_name == 0 || file_name[0] == 0)
	{
		print_stderr_no_exit("syntax error near unexpected token `newline'", \
		FAIL);
		return (0);
	}
	info = (t_file_info *)malloc(sizeof(t_file_info));
	if (info == 0)
		print_stderr("MALLOC");
	error = 0;
	info->file_name = file_name_quote(file_name, &error);
	info->write_mode = write_mode;
	info->next = 0;
	if (error == 1)
	{
		print_stderr_no_exit("ambiguous redirect", \
		FAIL);
		free(info->file_name);
		free(info);
		return (0);
	}
	return (info);
}

void	ft_push_back(t_file_info **head, t_file_info **node)
{
	t_file_info	*tmp;

	if (*head == 0)
		(*head) = (*node);
	else
	{
		tmp = (*head);
		while (tmp->next != 0)
			tmp = tmp->next;
		tmp->next = (*node);
	}
}

int	normalize_redirect(char *dup, char *command, int *is_mode)
{
	int	i;

	(*is_mode) = 0;
	if (ft_strncmp(command, ">>", 2) == 0 || \
	ft_strncmp(command, "<<", 2) == 0)
		(*is_mode) = 2;
	else if (command[0] == '>' || command[0] == '<')
		(*is_mode) = 1;
	if ((*is_mode) != 0)
		ft_strlcpy(dup, command, (*is_mode) + 1);
	i = (*is_mode);
	while (command[i] && command[i] == ' ')
		i++;
	return (i);
}

char	*change_commend_utility(char *cmd, char value, int i, int s_idx)
{
	char	*tmp;

	value = cmd[i];
	cmd[i] = 0;
	tmp = ft_strdup(&cmd[s_idx]);
	cmd[i] = value;
	return (tmp);
}
