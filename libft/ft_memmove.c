/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:27:47 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/09 17:41:34 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			l;

	if (dst == src || len == 0)
		return (dst);
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if (str1 > str2)
	{
		l = len;
		while (l--)
			*(str1 + l) = *(str2 + l);
	}
	else
	{
		l = 0;
		while (l < len)
		{
			str1[l] = str2[l];
			l++;
		}
	}
	return (str1);
}
