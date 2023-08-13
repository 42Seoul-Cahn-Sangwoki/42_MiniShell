/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:54:17 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/10 15:30:01 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

t_file_info	*get_info(char *file_name, int write_mode)
{
	t_file_info	*info;

	if (file_name[0] == 0 || file_name == 0)
		print_stderr("missing: file name");
	printf("file_name: [%s]\n", file_name);
	info = (t_file_info *)malloc(sizeof(t_file_info));
	info->file_name = ft_strdup(file_name);
	info->write_mode = write_mode;
	info->next = 0;
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
