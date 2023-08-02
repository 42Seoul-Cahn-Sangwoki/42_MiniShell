/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:43:41 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/02 18:23:05 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"signal.h"

// not print -> SIGQUIT: "^\", print -> SIGQUIT: "^\Quit: 3\n"
void	sig_handler(int signum)
{
	if (signum == SIGINT && getpid() == -1)
	{
		signal(SIGTERM, SIG_DFL);
		printf("\n");
		return ;
	}
	if (signum == SIGINT)
		printf("^C\n");
	else if (signum == SIGQUIT)
	{
		
	}
	exit(0);
}

void	init_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, 0) == -1 || sigaction(SIGQUIT, &sa, 0) == -1 \
	|| sigaction(SIGTERM, &sa, 0) == -1)
	{
		perror("Error setting up sigaction");
		return (1);
	}
}

void	init_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	set_signal_terminal(int argc, char *argv[])
{
	argc = 0;
	argv = 0;
	init_signal();
	init_terminal();
}
