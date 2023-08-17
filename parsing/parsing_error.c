/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:01:14 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/17 17:41:57 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_pipe(char *cmd)
{
	char	**pipe_split;
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(&cmd[i], "||", 2) == 0)
			print_stderr_no_exit("| is consequtive", FAIL);
		i++;
	}
	pipe_split = ft_split(cmd, '|');
	i = 0;
	while (pipe_split[i])
	{
		if (is_whitespace(pipe_split[i]))
			print_stderr_no_exit("white space between |", FAIL);
		i++;
	}
	free_split(&pipe_split);
}

int	error_symbol(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
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
