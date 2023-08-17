/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:43:41 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/17 20:23:44 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"signal.h"
#include <readline/readline.h>
#include <readline/history.h>

void	execute_handler(int signum)
{
	if (signum == SIGINT)
	{
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
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_global_var.exit = signum % 256;
	}
}

void	execute_signal(void)
{
	term_echo_on();
	signal(SIGINT, execute_handler);
	signal(SIGQUIT, execute_handler);
}

void	default_signal(void)
{
	term_echo_off();
	signal(SIGINT, default_handler);
	signal(SIGQUIT, SIG_IGN);
}
