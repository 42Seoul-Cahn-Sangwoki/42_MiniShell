/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:01:14 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/23 19:58:07 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_pipe(char *cmd, int *error)
{
	int	i;
	int	next_can_pipe;

	i = 0;
	next_can_pipe = 0;
	while (cmd[i] && *error == 0)
	{
		while (cmd[i] && (cmd[i] == ' ' || (9 <= cmd[i] && cmd[i] <= 13)))
			i++;
		if (cmd[i] == 0)
			break ;
		if (cmd[i] != '|')
			next_can_pipe = 1;
		else if (cmd[i] == '|' && next_can_pipe == 0)
			*error = 1;
		else if (cmd[i] == '|')
			next_can_pipe = 0;
		i++;
	}
	if (next_can_pipe == 0)
		*error = 1;
}

void	error_quote_pipe(char *cmd, int *error)
{
	int	i;
	int	next_not_pipe;

	i = 0;
	next_not_pipe = 0;
	while (cmd[i] && *error == 0)
	{
		while (cmd[i] && (cmd[i] == ' ' || (9 <= cmd[i] && cmd[i] <= 13)))
			i++;
		if (cmd[i] == 0)
			break ;
		if (ft_strncmp(&cmd[i], "<<", 2) == 0 || \
		ft_strncmp(&cmd[i], ">>", 2) == 0)
		{
			next_not_pipe = 1;
			i++;
		}
		else if (cmd[i] == '<' || cmd[i] == '>')
			next_not_pipe = 1;
		else if (cmd[i] == '|' && next_not_pipe)
			*error = 1;
		else
			next_not_pipe = 0;
		i++;
	}
}

int	error_symbol(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		while (command[i] && (command[i] == '\'' || command[i] == '\"'))
			i = find_next_quote(command, command[i], i + 1) + 1;
		if (command[i] == 0)
			break ;
		if (command[i] == ';' || command[i] == '\\')
			break ;
		if (ft_strncmp(&command[i], "$$", 2) == 0)
			break ;
		i++;
	}
	return (i != (int)ft_strlen(command));
}

int	error_handling(char **corpus)
{
	int		i;
	int		failure;

	i = 0;
	failure = FALSE;
	while (corpus[i] && failure == FALSE)
	{
		if (error_symbol(corpus[i]))
			failure = TRUE;
		i++;
	}
	return (failure);
}
