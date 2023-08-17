/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:10:14 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/14 14:11:52 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	n;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	p = 0;
	p = malloc(count * size);
	if (p == 0)
		return (0);
	n = 0;
	while (n < count * size)
	{
		*(unsigned char *)(p + n) = 0;
		n++;
	}
	return (p);
}
