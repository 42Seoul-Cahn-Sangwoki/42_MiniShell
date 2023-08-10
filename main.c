/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:52:23 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/09 14:20:02 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing/parsing.h"

char	**g_envp;

void	execute(t_node	**token, int length)
{
	t_file_info	*head1;
	t_file_info	*head2;
	char		**command;
	int			i;
	int			j;

	// printf("length: %d\n", length);
	i = 0;
	while (i < length)
	{
		j = 0;
		command = token[i]->commands;
		while (command[j])
		{
			printf("commands: [%s]\n", command[j]);
			j++;
		}
		head1 = token[i]->infile_head;
		while (head1)
		{
			printf("[%s %d]\n", head1->file_name, head1->write_mode);
			head1 = head1->next;
		}
		head2 = token[i]->outfile_head;
		while (head2)
		{
			printf("[%s %d]\n", head2->file_name, head2->write_mode);
			head2 = head2->next;
		}
		printf("\n\n\n\n");
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_node	**token;
	int		length;

	g_envp = envp;
	argc = 0;
	argv = 0;
	// set_signal_terminal(argc, argv);
	while (1)
	{
		line = readline(" $>");
		if (line == 0)
			break ;
		if (line[0] != '\0')
			add_history(&line[ft_strlen(" $>")]);
		if (line[0] != '\0' && !is_whitespace(line))
		{
			token = command_line(line, &length);
			if (token == 0)
				break ;
			execute(token, length);
		}
		free(line);
		// free_token(token);
	}
	return (0);
}
