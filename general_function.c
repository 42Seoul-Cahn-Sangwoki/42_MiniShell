/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:39:57 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/17 14:48:57 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

// default is 0
void	exit_status(int code)
{
	if (code == SUCCESS)
		g_global_var.exit = SUCCESS;
	else if (code == FAIL)
		g_global_var.exit = FAIL;
	else
		g_global_var.exit = code + 128;
}

void	non_valid_error(char *error_print)
{
	int	len;

	len = ft_strlen(error_print);
	write(1, error_print, len);
	write(1, " is not valid.\n", 16);
	exit_status(FAIL);
	exit(1);
}

void	print_stderr(const char *error_print)
{
	perror(error_print);
	exit_status(FAIL);
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
