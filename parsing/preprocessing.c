/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:19:16 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/01 17:33:06 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

int	is_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || (9 <= line[i] && line[i] <= 13)))
		i++;
	if (i == (int)ft_strlen(line))
		return (1);
	return (0);
}

int	pipex_count(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ('|' == line[i])
			count++;
		i++;
	}
	return (count);
}

t_node	**init_token(int pipex_counter)
{
	t_node	**node;

	node = (t_node **)malloc(sizeof(t_node *) * (pipex_counter + 1));
	return (node);
}

