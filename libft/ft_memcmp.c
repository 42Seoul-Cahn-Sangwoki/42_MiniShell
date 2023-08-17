/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:27:58 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/11 14:55:19 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

#include<stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			idx;
	int				ret;

	idx = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	ret = 0;
	while (ret == 0 && idx < n)
	{
		ret = str1[idx] - str2[idx];
		if (ret != 0)
			return (ret);
		idx++;
	}
	return (ret);
}
