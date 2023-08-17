/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:43:45 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/17 21:00:38 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"interface.h"
#include"parsing/parsing.h"
#include"signal/signal.h"

// void	ft_execute(t_node *token, int length)
// {
// 	int			i;
// 	int			cmd_idx;
// 	t_file_info	*head1;
// 	t_file_info	*head2;

// 	printf("length : %d\n", length);
// 	i = 0;
// 	while (token[i])
// 	{
// 		printf("pipe: ");
// 		cmd_idx = 0;
// 		while (token[i].commands[cmd_idx])
// 		{
// 			printf("[%s] ", token[i].commands[cmd_idx]);
// 			cmd_idx++;
// 		}
// 		printf("\n");
// 		head1 = token[i].infile_head;
// 		if (head1 != 0)
// 		{
// 			while (head1)
// 			{
// 				printf("[%s %d]\n", head1.file_name, head1.write_mode);
// 				head1 = head1.next;
// 			}
// 		}
// 		printf("\n\n\n");
// 		head2 = token[i].outfile_head;
// 		if (head2 != 0)
// 		{
// 			while (head2)
// 			{
// 				printf("[%s %d]\n", head2.file_name, head2.write_mode);
// 				head2 = head2.next;
// 			}
// 		}
// 		i++;
// 	}
// }

void	init_env(int argc, char *argv[], char *envp[])
{
	argv = 0;
	argc = 0;
	g_global_var.envp_head = copy_env_return_head(envp);
	g_global_var.exit = 0;
}

// ft_exeucte -> execute
void	valid_command_line(char *line)
{
	int		length;
	t_node	*token;

	token = command_line(line, &length);
	if (token == 0)
		print_stderr_no_exit("missing: format", FAIL);
	execute_signal();
	execute(token, length);
	free(token);
}
