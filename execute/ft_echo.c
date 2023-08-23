/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:17:59 by cahn              #+#    #+#             */
/*   Updated: 2023/08/23 14:34:22 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static int	is_option(char *str)
{
	int	i;

	if (ft_strncmp(str, "-n", 2))
		return (0);
	i = 2;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		++i;
	}
	return (1);
}

int	ft_echo(char **parameter)
{
	int	i;
	int	opt;

	i = 1;
	opt = 0;
	while (parameter[i])
	{
		if (is_option(parameter[i]))
			opt = 1;
		else
			printf("%s ", parameter[i]);
		++i;
	}
	if (!opt)
		printf("\n");
	return (set_exit_status(0, NULL, NULL));
}
