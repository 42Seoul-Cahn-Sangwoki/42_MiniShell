/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:54:34 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/25 20:47:31 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

int	exclude_whitespace(char *str, int is_whitespace, int s_idx)
{
	int	i;

	if (is_whitespace == FALSE)
		return (s_idx);
	i = s_idx;
	while (str[i] && str[i] != ' ' && !(9 <= str[i] && str[i] <= 13))
	{
		if (str[i] == '\'' || str[i] == '\"')
			break ;
		if (str[i] == '<' || str[i] == '>')
			return (i);
		i++;
	}
	while (str[i] && (str[i] == '\'' || str[i] == '\"'))
		i = find_next_quote(str, str[i], i + 1) + 1;
	if ((str[i] && (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))) || !str[i])
		return (i);
	return (exclude_whitespace(str, is_whitespace, i));
}

size_t	mk_branch_group(char *str, int is_white)
{
	size_t	i;
	size_t	mark;
	size_t	rank;

	rank = 0;
	i = 0;
	if (is_white && str[0] != ' ' && !(9 <= str[0] && str[0] <= 13))
	{
		i = exclue_redirect(str, 0);
		if (i == 0)
			i = exclude_whitespace(str, is_white, 0);
		rank++;
	}
	while (str[i])
	{
		mark = i;
		i = exclue_redirect(str, i);
		if (mark == i)
			i = exclude_whitespace(str, is_white, i);
		if (i != mark)
			rank++;
		else
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
		i = exclue_redirect(str, i);
		if (mark == i)
			i = exclude_whitespace(str, (flag & 3), i);
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

char	**ft_split_group(char *s, int is_whitespace, int is_quote)
{
	char	**branch;
	size_t	size;
	size_t	i;

	size = 0;
	if (s)
		size = mk_branch_group(s, is_whitespace);
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
