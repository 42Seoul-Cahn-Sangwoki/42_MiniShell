/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:36:02 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/14 11:33:20 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set(char ch, char const *set)
{
	size_t	s;

	s = 0;
	if (! set)
		return (0);
	while (set[s])
	{
		if (ch == set[s])
			return (1);
		s++;
	}
	return (0);
}

size_t	ft_strtrim_length(char const *str, char const *set)
{
	size_t	s;
	size_t	mark;
	size_t	length;

	s = 0;
	if (ft_strlen(str) == 0)
		return (0);
	length = 0;
	while (str[s] && is_set(str[s], set) == 1)
		s++;
	mark = s;
	while (str[s])
		s++;
	s--;
	while (is_set(str[s], set) == 1)
	{
		if (s == 0)
			break ;
		s--;
	}
	if (mark > s)
		return (0);
	length = s - mark + 1;
	return (length);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	idx;
	size_t	i;
	char	*str;
	size_t	length;

	length = ft_strtrim_length(s1, set);
	str = 0;
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (! str)
		return (0);
	idx = 0;
	while (s1[idx] && is_set(s1[idx], set) == 1)
		idx++;
	i = 0;
	while (i < length)
	{
		str[i] = s1[idx];
		i++;
		idx++;
	}
	str[i] = 0;
	return (str);
}
