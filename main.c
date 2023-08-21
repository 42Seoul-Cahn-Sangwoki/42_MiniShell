/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:33:14 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/21 14:53:01 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing/parsing.h"
#include"signal/signal.h"

// when ctrl + D -> eof. print exit.
// ========================================== //
// valid_command_line has execute and parsing
// ========================================== //
int	main(int argc, char *argv[], char *envp[])
{
	char	*line;

	init_env(argc, argv, envp);
	while (1)
	{
		default_signal();
		line = readline(" $> ");
		if (line == 0)
		{
			printf("\033[A\b\b\b $> exit\n");
			// 이 위치에 exit를 넣어야 할 것으로 보임
			break ;
		}
		if (line[0] != 0)
			add_history(&line[0]);
		if (line[0] != 0 && !is_whitespace(line))
			valid_command_line(line);
		free(line);
	}
	return (0);
}
