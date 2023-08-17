/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:43:41 by sangwoki          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/17 20:23:44 by sangwoki         ###   ########.fr       */
=======
/*   Updated: 2023/08/17 22:53:58 by sangwoki         ###   ########.fr       */
>>>>>>> merge_test
/*                                                                            */
/* ************************************************************************** */

#include"signal.h"
#include <readline/readline.h>
#include <readline/history.h>

void	execute_handler(int signum)
{
	if (signum == SIGINT)
	{
<<<<<<< HEAD
		ft_putchar_fd('\n', STDOUT_FILENO);
		g_global_var.exit = signum % 256;
		exit(signum % 256);
	}
	else if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDIN_FILENO);
		g_global_var.exit = signum % 256;
		exit(signum % 256);
	}
}

void	default_handler(int signum)
{
	if (signum == SIGINT)
=======
		g_global_var.exit = (128 | signum % 256);
		exit((128 | signum % 256));
	}
	else if (signum == SIGQUIT)
	{
		g_global_var.exit = (128 | signum % 256);
		exit((128 | signum % 256));
	}
}

void	execute_parent_hanlder(int signum)
{
	if (signum == SIGINT)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		g_global_var.exit = (128 | signum % 256);
	}
	else if (signum == SIGQUIT)
	{
		ft_putstr_fd("Quit: 3\n", STDIN_FILENO);
		g_global_var.exit = (128 | signum % 256);
	}
}

void	default_handler(int signum)
{
	if (signum == SIGINT)
>>>>>>> merge_test
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
<<<<<<< HEAD
		g_global_var.exit = signum % 256;
=======
		g_global_var.exit = (128 | signum % 256);
>>>>>>> merge_test
	}
}

void	execute_signal(void)
{
<<<<<<< HEAD
	term_echo_on();
	signal(SIGINT, execute_handler);
	signal(SIGQUIT, execute_handler);
}

=======
	term_echo_off();
	signal(SIGINT, execute_handler);
	signal(SIGQUIT, execute_handler);
}

void	execute_parent_signal(void)
{
	term_echo_on();
	signal(SIGINT, execute_parent_hanlder);
	signal(SIGQUIT, execute_parent_hanlder);
}

// default is 0
>>>>>>> merge_test
void	default_signal(void)
{
	term_echo_off();
	signal(SIGINT, default_handler);
	signal(SIGQUIT, SIG_IGN);
}
