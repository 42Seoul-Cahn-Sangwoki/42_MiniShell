/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:54:34 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/12 22:45:48 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	mk_branch(const char *str, char c)
{
	size_t	i;
	size_t	rank;

	rank = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if (str[0] != c)
		rank++;
	i = 1;
	while (str[i])
	{
		if (str[i - 1] == c)
		{
			if (str[i] != c)
				rank++;
		}
		i++;
	}
	return (rank);
}

char	*mk_leaf(const char *str, size_t len)
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

size_t	mk_tree(char const *s, char c, size_t size, char **branch)
{
	size_t	mark;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (j < size)
	{
		mark = i;
		while (s[i] && s[i] != c)
			i++;
		if (mark != i)
		{
			branch[j] = mk_leaf(&s[mark], i - mark);
			if (! branch[j])
				return (j);
			j++;
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**branch;
	size_t	size;
	size_t	i;

	size = 0;
	if (s)
		size = mk_branch(s, c);
	branch = 0;
	branch = (char **)malloc(sizeof(char *) * (size + 1));
	if (! branch)
		return (0);
	branch[size] = 0;
	i = mk_tree(s, c, size, branch);
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

// 	p = ft_split("hello!", 'a');
// 	i = 0;
// 	while (p[i])
// 	{
// 		printf("%s\n", p[i]);
// 		i++;
// 	}
// 	if (p[i] == 0)
// 		printf("good");
// 	return (0);
// }