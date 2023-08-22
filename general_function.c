/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:34 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 17:00:43 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	print_stderr_no_exit(char *command, int code)
{
	g_global_var.exit = code % 256;
	printf("minishell: %s: %s\n", command, strerror(g_global_var.exit));
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
