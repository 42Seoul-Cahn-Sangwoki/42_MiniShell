/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
<<<<<<< HEAD:signal/signal.h
/*   signal.h                                           :+:      :+:    :+:   */
=======
/*   ft_echo.c                                          :+:      :+:    :+:   */
>>>>>>> merge_test:execute/ft_echo.c
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:signal/signal.h
/*   Created: 2023/08/02 11:44:08 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/12 21:38:02 by sangwoki         ###   ########.fr       */
=======
/*   signal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:44:08 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/17 22:31:47 by sangwoki         ###   ########.fr       */
>>>>>>> merge_test
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

<<<<<<< HEAD
#endif
=======
/*   Created: 2023/08/14 15:17:59 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 13:34:57 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

void    ft_echo(char **parameter)
{
    int i;

    i = 1;
    while (parameter[i])
    {
        printf("%s ", parameter[i]);
        ++i;
    }
    printf("\n");
}
>>>>>>> merge_test:execute/ft_echo.c
=======
void	execute_parent_hanlder(int signum);
void	execute_parent_signal(void);

#endif
>>>>>>> merge_test
