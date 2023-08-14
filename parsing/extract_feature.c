/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_feature.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:39:58 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/14 23:20:15 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// normalize: <file <<EOF >file >>file
// tokenizer
// -> command: vectorize => ft_split
// -> infile, outfile: linked_list;

#include"parsing.h"

char	**extract_command(char **command, int length)
{
	char	*tmp;
	char	**extract;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (length * 2));
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
	extract = ft_split_group(tmp, TRUE, TRUE);
	free(tmp);
	return (extract);
}

t_file_info	*extract_infile(char **command)
{
	int			i;
	t_file_info	*head;
	t_file_info	*node;

	i = 0;
	head = 0;
	while (command[i])
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
		i++;
	}
	return (head);
}

t_file_info	*extract_outfile(char **command)
{
	int			i;
	t_file_info	*head;
	t_file_info	*node;

	i = 0;
	head = 0;
	while (command[i])
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
		i++;
	}
	return (head);
}
