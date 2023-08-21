/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:41:58 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/21 14:42:00 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include"../interface.h"

# include <signal.h>
# include <termios.h>
# include <sys/types.h>
# include <unistd.h>

void	exit_status(int code);
void	execute_handler(int signum);
void	default_handler(int signum);
void	execute_signal(void);
void	default_signal(void);
void	term_echo_off(void);
void	term_echo_on(void);
void	execute_parent_hanlder(int signum);
void	execute_parent_signal(void);

#endif
