/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:43:45 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/22 20:46:30 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"interface.h"
#include"parsing/parsing.h"
#include"signal/signal.h"

void	free_file_node(t_file_info **head)
{
	t_file_info	*search;
	t_file_info	*tmp;

	search = *head;
	while (search != NULL)
	{
		tmp = search->next;
		free(search->file_name);
		free(search);
		search = tmp;
	}
}

void	free_token(t_node *token, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free_split(&token[i].commands);
		free_file_node(&token[i].infile_head);
		free_file_node(&token[i].outfile_head);
		++i;
	}
	free(token);
}

void	execute_shell(char ***command)
{
	char	**new_cmd;

	if ((*command) == 0 || (*command)[0] == 0)
		return ;
	if (ft_strncmp((*command)[0], "./minishell", ft_strlen("./minishell")))
		return ;
	new_cmd = (char **)malloc(sizeof(char *) * 3);
	new_cmd[0] = ft_strdup((*command)[0]);
	new_cmd[1] = ft_strdup(search_node_by_key(g_global_var.envp_head, \
	"SHLVL")->value);
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
		free(shlvl);
	}
	else
	{
		node = search_node_by_key(g_global_var.envp_head, "SHLVL");
		shlvl = ft_itoa(ft_atoi(node->value) + 1);
		modify_env_value(node, shlvl);
		free(shlvl);
	}
	argv = 0;
	argc = 0;
}

void	valid_command_line(char *line)
{
	int		length;
	t_node	*token;

	token = command_line(line, &length);
	if (token == 0)
	{
		print_stderr_no_exit("missing: format", FAIL);
		return ;
	}
	execute_signal();
	execute(token, length);
	free_token(token, length);
}
