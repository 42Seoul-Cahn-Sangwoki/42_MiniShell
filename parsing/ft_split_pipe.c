/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:54:34 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/23 18:57:57 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"
// #define TRUE 1
// int	find_next_quote(char *cmd, char quote, int i)
// {
// 	while (cmd[i] && cmd[i] != quote)
// 		i++;
// 	if (cmd[i] == 0)
// 		printf("%s", "quote is unbalance\n");
// 	return (i);
// }

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

// export var ="cat Makefile | grep >"
// #include<stdio.h>

// int	main(void)
// {
// 	char	**p;
// 	int		i;
// 	char	*test;

// 	test = "echo \"\'$?  $HOME|$HOME|$HOME\'\'\'\" | \"\'$HOME$? $\'\"  ";
// 	p = ft_split_pipe(test);
// 	i = 0;
// 	while (p[i])
// 	{
// 		printf("[%s]\n", p[i]);
// 		i++;
// 	}
// 	if (p[i] == 0)
// 		printf("good");
// 	return (0);
// }