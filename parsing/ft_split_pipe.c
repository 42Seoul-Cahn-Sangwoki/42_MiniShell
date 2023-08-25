/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:54:34 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/25 20:47:40 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

int	exclude_pipe(char *str, int s_idx)
{
	int	i;

	i = s_idx;
	while (str[i] && str[i] != '|')
	{
		if (str[i] == '\'' || str[i] == '\"')
			break ;
		i++;
	}
	while (str[i] && (str[i] == '\'' || str[i] == '\"'))
	{
		i = find_next_quote(str, str[i], i + 1) + 1;
		if (i < 0)
			return (-1);
	}
	if ((str[i] && str[i] == '|') || !str[i])
		return (i);
	return (exclude_pipe(str, i));
}

int	mk_branch_pipe(char *str)
{
	int	i;
	int	mark;
	int	rank;

	rank = 0;
	i = 0;
	if (str[0] != '|')
	{
		i = exclude_pipe(str, 0);
		if (i < 0)
			return (-1);
		rank++;
	}
	while (str[i])
	{
		mark = i;
		i = exclude_pipe(str, i);
		if (i < 0)
			return (-1);
		if (i != mark)
			rank++;
		else
			i++;
	}
	return (rank);
}

int	mk_tree_pipe(char *str, int size, char **branch)
{
	int	mark;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < size)
	{
		mark = i;
		i = exclude_pipe(str, i);
		if (mark != i)
		{
			branch[j] = mk_leaf_group(&str[mark], i - mark);
			if (! branch[j])
				return (j);
			j++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split_pipe(char *s, int *size)
{
	char	**branch;
	int		i;

	if (s)
		(*size) = mk_branch_pipe(s);
	if (*size < 0)
		return (0);
	branch = 0;
	branch = (char **)malloc(sizeof(char *) * ((*size) + 1));
	if (! branch)
		return (0);
	branch[(*size)] = 0;
	i = mk_tree_pipe(s, (*size), branch);
	if ((*size) != i)
	{
		i = 0;
		while (branch[i])
		{
			free(branch[i]);
			i++;
		}
		free(branch);
		return (0);
	}
	return (branch);
}
