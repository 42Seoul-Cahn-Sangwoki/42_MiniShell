/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:01:14 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/01 19:49:41 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// signal error: 

// parsing error: \, ;, ', "

int	error_symbol(char *command)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (command[i] == ';' || command[i] == '\\')
			break ;
		i++;
	}
	return (i != (int)ft_strlen(command));
}

int	error_bracket(char *command)
{
	int	i;
	int	j;
	int	failure;

	failure = FALSE;
	i = 0;
	j = ft_strlen(command) - 1;
	while (i < j && failure == FALSE)
	{
		while (command[i] && (command[i] != '\'' && command[i] != '\"'))
			i++;
		while (j >= 0 && (command[j] != '\'' && command[j] != '\"'))
			j--;
		if ((j >= 0 && command[i] != command[j]))
			failure = TRUE;
		i++;
		j--;
	}
	return (failure == TRUE);
}

int	error_handling(char **corpus)
{
	int		i;
	int		failure;

	i = 0;
	failure = FALSE;
	while (corpus[i] && failure == FALSE)
	{
		if (error_bracket(corpus[i]) || error_symbol(corpus[i]))
			failure = TRUE;
		i++;
	}
	return (failure);
}