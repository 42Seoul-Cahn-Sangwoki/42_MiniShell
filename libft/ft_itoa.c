/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:46:10 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/11 11:22:25 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	allocate_size(long n)
{
	if (n == 0)
		return (0);
	return (allocate_size(n / 10) + 1);
}

char	*allocate(long n, int sign, int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + sign + 1));
	if (! str)
		return (0);
	str[size + sign] = 0;
	if (size == 0)
	{
		str[size] = '0';
		return (str);
	}
	size = size + sign - 1;
	while (size >= 0)
	{
		if (sign == 1 && size == 0)
		{
			str[size] = '-';
			break ;
		}
		str[size] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	long	num;
	char	*str;

	num = n;
	sign = 0;
	if (num <= 0)
	{
		num = -num;
		sign = 1;
	}
	size = allocate_size(num);
	str = allocate(num, sign, size);
	return (str);
}
