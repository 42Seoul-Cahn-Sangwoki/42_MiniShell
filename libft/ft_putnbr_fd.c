/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:47:17 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/10 20:56:23 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num / 10 != 0)
		ft_putnbr_fd(num / 10, fd);
	if (num < 0)
	{
		num = -num;
		if (num / 10 == 0)
			ft_putchar_fd('-', fd);
	}
	ft_putchar_fd(num % 10 + '0', fd);
}
