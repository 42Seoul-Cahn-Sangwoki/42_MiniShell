/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:52:25 by sangwoki          #+#    #+#             */
/*   Updated: 2023/07/30 14:57:17 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include "libft/libft.h"
# include <signal.h>
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define FALSE 0
# define TRUE 1
# define CMD 0
# define OPTION 1

typedef struct s_state
{
	int		is_pipex;
	int		is_error;
}	t_state;

// command[0] == cmd, command[1] == option
typedef struct s_node
{
	char			*command[2];
	int				idx;
	t_state			state;
	struct s_node	*next;
}	t_node;

#endif