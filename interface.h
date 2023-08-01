/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:33:43 by cahn              #+#    #+#             */
/*   Updated: 2023/08/01 17:11:36 by sangwoki         ###   ########.fr       */
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

// 여기 매크로값 넣어주셈 (> 이거는 0, >> 이거는 1, inputfile이면 -1)
// open: <, heredoc: <<
// write: >, append: >> 

typedef struct s_file_info
{
	char				*file_name;
	int					write_mode;
	struct s_file_info	*next;
}	t_file_info;

typedef struct s_node
{
	char			**commands;
	t_file_info		*infile_head;
	t_file_info		*outfile_head;
}	t_node;

// void	execute(t_node *cmds, int length); // 배열과 배열 크기(크기 꼭 리턴)
void	print_stderr(char *error_print);
void	non_valid_error(char *error_print);

#endif