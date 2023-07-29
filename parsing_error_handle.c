/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_handle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:01:14 by sangwoki          #+#    #+#             */
/*   Updated: 2023/07/29 22:02:49 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	error_handliing(char **corpus)
{
	int	i;
	int	is_pipex_turn;
	int	is_error;

	i = 0;
	is_pipex_turn = FALSE;
	is_error = FALSE;
	while (corpus[i])
	{
		if ((is_pipex_turn == TRUE && ft_strncmp(corpus[i], "||", 2) != 0) \
		|| (is_pipex_turn == FALSE && ft_strncmp(corpus[i], "||", 2) == 0))
		{
			is_error = TRUE;
			free_corpus(corpus);
			break ;
		}
		if (is_pipex_turn == FALSE && ft_strncmp(corpus[i + 1], "||", 2) != 0)
			i++;
		if (is_pipex_turn)
			is_pipex_turn = FALSE;
		else
			is_pipex_turn = TRUE;
		i++;
	}
	return (is_error == TRUE);
}

void	free_corpus(char **curpus)
{
	int	i;

	i = 0;
	while (curpus[i])
	{
		free(curpus[i]);
		i++;
	}
}

void	free_token(t_node **node)
{
	t_node	*tmp;

	while ((*node))
	{
		tmp = (*node);
		free(tmp->command[0]);
		free(tmp->command[1]);
		(*node) = (*node)->next;
	}
}
