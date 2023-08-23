/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:34 by cahn              #+#    #+#             */
/*   Updated: 2023/08/23 13:35:41 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	print_stderr_no_exit(char *command, int code)
{
	g_global_var.exit = code % 256;
	strerror(g_global_var.exit);
	printf("minishell: %s\n", command);
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
