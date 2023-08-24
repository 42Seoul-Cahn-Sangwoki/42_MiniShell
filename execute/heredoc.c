/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:41:22 by cahn              #+#    #+#             */
/*   Updated: 2023/08/24 21:22:52 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"
#include "../signal/signal.h"

static void	process_manage_for_heredoc(t_file_info *find)
{
	char	*end;
	int		pid;
	int		stat;
	char	*tmpfile;

	signal(SIGINT, SIG_IGN);
	tmpfile = make_no_overlap_tmpfile();
	end = find->file_name;
	find->file_name = tmpfile;
	pid = fork();
	if (!pid)
	{
		execute_signal();
		change_tmpfile_name_by_here_document(end, tmpfile);
		exit(0);
	}
	waitpid(pid, &stat, 0);
	set_exit_status(stat >> 8, NULL, NULL);
	free(end);
	execute_signal();
}

int	create_heredoc_file(t_node *cmds, int length)
{
	int			i;
	t_file_info	*find;

	i = 0;
	while (i < length)
	{
		find = cmds[i].infile_head;
		while (find != NULL)
		{
			if (find->write_mode == HERE_DOC)
			{
				process_manage_for_heredoc(find);
				if (g_global_var.exit)
				{
					printf(">\n");
					delete_tmp_file(cmds, length);
					return (g_global_var.exit);
				}
			}
			find = find->next;
		}
		++i;
	}
	return (g_global_var.exit);
}

char	*make_no_overlap_tmpfile(void)
{
	unsigned long long	file_name;
	char				*num;
	char				*file_path;

	file_name = 0;
	num = ft_ultoa(file_name);
	file_path = ft_strjoin("/tmp/", num);
	free(num);
	while (!access(file_path, F_OK))
	{
		free(file_path);
		++file_name;
		num = ft_ultoa(file_name);
		file_path = ft_strjoin("/tmp/", num);
		free(num);
	}
	return (file_path);
}

static void	input_to_file_to_end_string(char *end_string, int tmp_fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (line)
		{
			if (!ft_strncmp(end_string, line, COMPARE_NUMBER))
			{
				free(line);
				break ;
			}
			write(tmp_fd, line, ft_strlen(line));
			write(tmp_fd, "\n", 1);
			rl_on_new_line();
			free(line);
		}
	}
}

void	change_tmpfile_name_by_here_document(char *end_string, char *tmp_file)
{
	int		tmp_fd;

	tmp_fd = open(tmp_file, O_WRONLY | O_CREAT | O_TRUNC, 00777);
	if (tmp_fd < 0)
		print_stderr(tmp_file);
	input_to_file_to_end_string(end_string, tmp_fd);
	if (close(tmp_fd) < 0)
		print_stderr("tmp_fd");
}
