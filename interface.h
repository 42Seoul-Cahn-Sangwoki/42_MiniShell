/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:33:43 by cahn              #+#    #+#             */
/*   Updated: 2023/07/31 17:45:31 by cahn             ###   ########.fr       */
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

typedef struct s_file_info
{
    char                *file_name; // Null 이면 fd값 확인
    int                 fd;
    struct s_file_info  *next;
}   t_file_info;

typedef struct s_node
{
    char            **commands; // 딱 명령어 만큼만 할당해주셈
    t_file_info     *infile_head; // head 더미노드로 할지 말지 알려주셈
    t_file_info     *outfile_head;
}   t_node;

void    execute(t_node *cmds, int length); // 배열과 배열 크기(크기 꼭 리턴)
void	print_stderr(char *error_print);
void	non_valid_error(char *error_print);

#endif