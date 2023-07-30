/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:12:14 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/11 16:24:04 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_join(char const *str)
{
	size_t	l;

	l = 0;
	if (! str)
		return (0);
	while (str[l])
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	l;
	char	*str;

	len = ft_strlen_join(s1) + ft_strlen_join(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (! str)
		return (0);
	str[len] = 0;
	l = 0;
	while (l < ft_strlen_join(s1))
	{
		str[l] = s1[l];
		l++;
	}
	l = 0;
	while (l < ft_strlen_join(s2))
	{
		str[l + ft_strlen_join(s1)] = s2[l];
		l++;
	}
	return (str);
}
