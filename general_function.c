/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:12:02 by cahn              #+#    #+#             */
/*   Updated: 2023/08/14 15:12:06 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	non_valid_error(char *error_print)
{
	int	len;

	len = ft_strlen(error_print);
	write(1, error_print, len);
	write(1, " is not valid.\n", 16);
	exit(1);
}

void	print_stderr(char *error_print)
{
	perror(error_print);
	exit(1);
}

void	free_split(char ***split)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *split;
	while (tmp[i])
	{
		free(tmp[i]);
		++i;
	}
	free(tmp);
}

