/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:43:41 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/10 14:51:36 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"signal.h"

int	g_exit;

void	exit_status(int code)
{
	
}

void	handler(int signum)
{
	char	ch;
	int		ret;

	ret = read(STDIN_FILENO, &ch, 1);
	if (signum == SIGINT)
	{
		// exit_status(256 * EXIT_FAILURE);
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		// exit_status(256 * EXIT_FAILURE);
		if (ret != 0)
			ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	execute_signal(void)
{
	term_echo_on();
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}

void	default_signal(void)
{
	term_echo_off();
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}

void	term_echo_off(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	term_echo_on(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	main(void)
{
	pid_t	child_pid;
	char	*line;

	default_signal();
	while (1)
	{
		line = readline(" $>");
		if (line == 0)
		{
			printf("exit\n");
			break ;
		}
		execute_signal();
		// child_pid = fork();
		// if (child_pid == 0)
		// 	set_signal(child_handler);
		sleep (100);
	}
	return (0);
}

