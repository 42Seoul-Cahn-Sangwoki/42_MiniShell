/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:10:27 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/13 13:10:38 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"signal.h"

int	main(void)
{
	char			*line;

	line = 0;
	while (1)
	{
		default_signal();
		line = readline("minishell $>");
		if (line == 0)
		{
			printf("exit\n");
			break ;
		}
		// execute
		printf("%s\n", line);
		execute_signal();
	}
	return (0);
}