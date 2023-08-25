/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_feature.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:39:58 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/25 20:47:23 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

char	**extract_command(char **command, int length)
{
	char	*tmp;
	char	**extract;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = allocate_tmp(length);
	while (command[i])
	{
		if (command[i][0] != '<' && command[i][0] != '>')
		{
			ft_strlcpy(&tmp[j], command[i], ft_strlen(command[i]) + 1);
			tmp[j + ft_strlen(command[i])] = ' ';
			j = j + ft_strlen(command[i]) + 1;
			tmp[j] = 0;
		}
		i++;
	}
	if (tmp[0])
		extract = ft_split_group(tmp, TRUE, TRUE);
	else
		extract = 0;
	free(tmp);
	return (extract);
}

char	*allocate_tmp(int length)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (length * 2 + 1));
	if (tmp == 0)
		print_stderr("MALLOC");
	tmp[0] = 0;
	return (tmp);
}

t_file_info	*extract_infile(char **command, int *error)
{
	int			i;
	t_file_info	*head;
	t_file_info	*node;

	i = 0;
	head = 0;
	while (command[i] && (*error == 0))
	{
		if (ft_strncmp(command[i], "<<", 2) == 0)
		{
			node = get_info(&command[i][2], HERE_DOC);
			ft_push_back(&head, &node);
		}
		else if (ft_strncmp(command[i], "<", 1) == 0)
		{
			node = get_info(&command[i][1], READ);
			ft_push_back(&head, &node);
		}
		if (node == 0)
			*error = 1;
		i++;
	}
	return (head);
}

t_file_info	*extract_outfile(char **command, int *error)
{
	int			i;
	t_file_info	*head;
	t_file_info	*node;

	i = 0;
	head = 0;
	while (command[i] && (*error == 0))
	{
		if (ft_strncmp(command[i], ">>", 2) == 0)
		{
			node = get_info(&command[i][2], WRITE_BACK);
			ft_push_back(&head, &node);
		}
		else if (ft_strncmp(command[i], ">", 1) == 0)
		{
			node = get_info(&command[i][1], WRITE_NEW);
			ft_push_back(&head, &node);
		}
		if (node == 0)
			*error = 1;
		i++;
	}
	return (head);
}
