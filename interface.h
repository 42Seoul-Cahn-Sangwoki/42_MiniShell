/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:42:56 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/15 15:48:44 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "libft/libft.h"
# include <signal.h>
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define WRITE_NEW 0
# define WRITE_BACK 1
# define READ -1
# define HERE_DOC -2
# define SUCCESS 1
# define FAIL 0

typedef struct s_file_info
{
	char				*file_name;
	int					fd;
	int					write_mode;
	struct s_file_info	*next;
}	t_file_info;

typedef struct s_node
{
	char			**commands;
	t_file_info		*infile_head;
	t_file_info		*outfile_head;
}	t_node;

typedef struct s_global
{
	char	**envp;
	int		exit;
}	t_global;

t_global	g_global_var;

void	execute(t_node *cmds, int length);
void	print_stderr(char *error_print);
void	non_valid_error(char *error_print);
void	free_split(char ***split);
void	init_env(int argc, char *argv[], char *envp[]);
void	valid_command_line(char *line);

#endif