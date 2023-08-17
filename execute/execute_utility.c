/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:46:55 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 16:35:07 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static int	count_digit_pos(unsigned long long n)
{
	if (n == 0)
		return (0);
	return (1 + count_digit_pos(n / 10));
}

static void	put_num_to_str(char *numstr, unsigned long long n, int *index)
{
	if (n > 0)
	{
		put_num_to_str(numstr, n / 10, index);
		numstr[*index] = n % 10 + '0';
		(*index)++;
	}
}

static int	count_digit_by_sign(unsigned long long n)
{
	if (n == 0)
		return (1);
	else
		return (count_digit_pos(n));
}

char	*ft_ultoa(unsigned long long n)
{
	char		*numstr;
	int			index;

	numstr = (char *)malloc(sizeof(char) * (count_digit_by_sign(n) + 1));
	if (!numstr)
		print_stderr("Malloc");
	index = 0;
	if (n == 0)
		numstr[index++] = '0';
	else
		put_num_to_str(numstr, n, &index);
	numstr[index++] = 0;
	return (numstr);
}