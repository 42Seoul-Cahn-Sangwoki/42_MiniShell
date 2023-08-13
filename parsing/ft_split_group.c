/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:54:34 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/13 20:10:27 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # define TRUE 1
// # define FALSE 0
// # include <stdio.h>
// # include <unistd.h>
// # include <stdlib.h>

// int	find_next_quote(char *cmd, char quote, int i)
// {
// 	while (cmd[i] && cmd[i] != quote)
// 		i++;
// 	if (cmd[i] == 0)
// 	{
// 		printf("quote is unbalance\n");
// 		exit(0);
// 	}
// 	// printf("find_next_quote : %d, %c\n", i, cmd[i]);
// 	return (i);
// }

#include"parsing.h"

int	exclude_whitespace(char *str, int is_whitespace, int s_idx)
{
	int	i;

	if (is_whitespace == FALSE)
		return (s_idx);
	i = s_idx;
	while (str[i] && str[i] != ' ' && !(9 <= str[i] && str[i] <= 13))
		i++;
	return (i);
}

size_t	mk_branch_group(char *str, int is_white, int is_quote)
{
	size_t	i;
	size_t	skip;
	size_t	rank;

	rank = 0;
	if (is_white && str[0] != ' ' && !(9 <= str[0] && str[0] <= 13))
		rank++;
	i = 1;
	while (str[i])
	{
		if (is_quote && (str[i] == '\'' || str[i] == '\"'))
		{
			i = find_next_quote(str, str[i], i + 1);
			rank++;
		}
		if (str[i - 1] == ' ' || (9 <= str[i - 1] && str[i - 1] <= 13))
		{
			if (is_white && str[i] != ' ' && !(9 <= str[i] && str[i] <= 13))
				rank++;
		}
		i++;
	}
	return (rank);
}

char	*mk_leaf_group(char *str, size_t len)
{
	char	*leaf;
	size_t	t;

	leaf = 0;
	leaf = (char *)malloc(sizeof(char) * (len + 1));
	if (! leaf)
		return (0);
	leaf[len] = 0;
	t = 0;
	while (t < len)
	{
		leaf[t] = str[t];
		t++;
	}
	return (leaf);
}

size_t	mk_tree_group(char *str, int flag, size_t size, char **branch)
{
	size_t	mark;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (j < size)
	{
		mark = i;
		if ((flag & 2) && (str[i] == '\'' || str[i] == '\"'))
			i = find_next_quote(str, str[i], i + 1) + 1;
		else if (flag & 1)
			i = exclude_whitespace(str, (flag & 1), i);
		if (mark != i)
		{
			branch[j] = mk_leaf_group(&str[mark], i - mark);
			if (! branch[j])
				return (j);
			j++;
		}
		i++;
	}
	return (j);
}

char	**ft_split_group(char *s, int is_whitespace, int is_quote)
{
	char	**branch;
	size_t	size;
	size_t	i;

	size = 0;
	if (s)
		size = mk_branch_group(s, is_whitespace, is_quote);
	branch = 0;
	branch = (char **)malloc(sizeof(char *) * (size + 1));
	if (! branch)
		return (0);
	branch[size] = 0;
	i = mk_tree_group(s, is_whitespace + (is_quote << 1), size, branch);
	if (size != i)
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

// #include<stdio.h>

// int	main(void)
// {
// 	char	**p;
// 	int		i;
// 	char	*test;

// 	test = "echo \"\'$?         $HOME$HOME$HOME$HOME$? $\'\"                go";
// 	p = ft_split_group(test, TRUE, TRUE);
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