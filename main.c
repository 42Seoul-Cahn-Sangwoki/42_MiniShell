/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:52:23 by sangwoki          #+#    #+#             */
/*   Updated: 2023/07/29 19:55:21 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"base.h"

char	*g_envp;

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	g_envp = envp;
	// 
	// signal part
	//
	while (1)
	{
		line = readline(" $>");
		if (line == 0)
			break ;
		if (line[0] != '\0')
			add_history(line);
		if (line[0] != '\0' && !is_whitespace(line))
		{
			// execute
		}
		free(line);
	}
	return (0);
}
