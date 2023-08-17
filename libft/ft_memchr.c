/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:19:29 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/11 20:39:57 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;

	ch = c;
	while (n > 0)
	{
		if (*(unsigned char *)s == ch)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}
