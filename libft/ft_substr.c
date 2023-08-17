/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:41:12 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/11 21:25:16 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	n;

	if (s == 0)
		return (0);
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	substr = 0;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	n = 0;
	while (n < len)
	{
		substr[n] = s[start + n];
		n++;
	}
	substr[len] = 0;
	return (substr);
}
