/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:49:34 by sangwoki          #+#    #+#             */
/*   Updated: 2023/07/29 22:00:59 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || (9 <= line[i] && line[i] <= 13)))
		i++;
	if (i == ft_strlen(line))
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
		if (ft_strncmp('||', line[i], 2) == 0)
			count++;
		i++;
	}
	return (count);
}

t_node	*init_token(int pipex_counter, char *line)
{
	t_node	*node;
	int		i;

	node = (t_node *)malloc(sizeof(t_node) * (pipex_counter * 2 + 1));
	i = 0;
	while (i < pipex_counter * 2 + 1)
	{
		node[i].command[CMD] = 0;
		node[i].command[OPTION] = 0;
		node[i].state.is_error = FALSE;
		node[i].state.is_pipex = FALSE;
		node[i].next = 0;
		if (i != pipex_counter * 2 + 1)
			node[i].next = &node[i + 1];
		i++;
	}
	return (node);
}

int	tokenizer(int pipex_couter, char *line, t_node **node)
{
	char	**corpus;
	int		i;
	int		j;

	corpus == ft_split(line, ' ');
	if (error_handling(corpus) == TRUE)
		return (FALSE);
	i = 0;
	j = 0;
	while (i < pipex_couter * 2 + 1)
	{
		(*node)[i].command[0] = corpus[j];
		(*node)[i].state.is_pipex = TRUE;
		if (ft_strncmp(corpus[j], "||", 2) != 0)
		{
			(*node)[i].state.is_pipex = FALSE;
			if (corpus[j + 1] != 0 && ft_strncmp(corpus[j + 1], "||", 2) != 0)
				(*node)[i].command[1] = corpus[++j];
		}
		j++;
		i++;
	}
	free_corpus(corpus);
	return (i);
}

t_node	*command_line(char *line)
{
	t_node	*token;
	int		pipex_counter;
	int		i;

	pipex_counter = pipex_count(line);
	token = init_token(pipex_counter, line);
	if (token == 0)
		return (FALSE);
	if (tokenizer(pipex_counter, line, &token) == FALSE)
	{
		free_token(&token);
		return (FALSE);
	}
	return (token);
}
