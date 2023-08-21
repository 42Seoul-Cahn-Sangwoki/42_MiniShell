

#include"signal.h"
#include <readline/readline.h>
#include <readline/history.h>

void	execute_handler(int signum)
{
	if (signum == SIGINT)
	{
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
		ft_putstr_fd("Quit: 3\n", STDOUT_FILENO);
		g_global_var.exit = (128 | signum % 256);
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
		g_global_var.exit = (128 | signum % 256);
	}
}

void	execute_signal(void)
{
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
void	default_signal(void)
{
	term_echo_off();
	signal(SIGINT, default_handler);
	signal(SIGQUIT, SIG_IGN);
}
