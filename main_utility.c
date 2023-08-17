/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:43:45 by sangwoki          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/17 20:43:27 by sangwoki         ###   ########.fr       */
=======
/*   Updated: 2023/08/17 23:36:25 by sangwoki         ###   ########.fr       */
>>>>>>> merge_test
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

<<<<<<< HEAD
void	init_env(int argc, char *argv[], char *envp[])
{
	argv = 0;
	argc = 0;
	g_global_var.envp_head = copy_env_return_head(envp);
	g_global_var.exit = 0;
=======
void	execute_shell(char ***command)
{
	char	**new_cmd;

	if (ft_strncmp((*command)[0], "./minishell", ft_strlen("./minishell")))
		return ;
	new_cmd = (char **)malloc(sizeof(char *) * 3);
	new_cmd[0] = ft_strdup((*command)[0]);
	new_cmd[1] = search_node_by_key(g_global_var.envp_head, "SHLVL")->value;
	new_cmd[2] = 0;
	free_split(command);
	(*command) = new_cmd;
}

void	init_env(int argc, char *argv[], char *envp[])
{
	t_env_node	*node;
	char		*shlvl;

	g_global_var.envp_head = copy_env_return_head(envp);
	g_global_var.exit = 0;
	if (argc >= 2)
	{
		node = search_node_by_key(g_global_var.envp_head, "SHLVL");
		shlvl = ft_itoa(ft_atoi(argv[1]) + 1);
		modify_env_value(node, shlvl);
	}
	argv = 0;
	argc = 0;
>>>>>>> merge_test
}

// ft_exeucte -> execute
void	valid_command_line(char *line)
{
	int		length;
	t_node	*token;

	token = command_line(line, &length);
	if (token == 0)
<<<<<<< HEAD
		print_stderr_no_exit("missing: format", FAIL);
	execute_signal();
	// ft_execute(token, length);
=======
	{
		print_stderr_no_exit("missing: format", FAIL);
		return ;
	}
	execute_signal();
	execute(token, length);
>>>>>>> merge_test
	free(token);
}
