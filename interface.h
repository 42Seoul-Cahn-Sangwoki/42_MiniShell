/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 16:33:43 by cahn              #+#    #+#             */
/*   Updated: 2023/07/30 17:42:19 by cahn             ###   ########.fr       */
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

typedef struct s_node
{
    char            **commands;
    int             idx;
    struct s_node	*next;
}   t_node;

void    execute(t_node *cmds, int length); // 배열과 배열 크기
void	print_stderr(char *error_print);
void	non_valid_error(char *error_print);

#endif