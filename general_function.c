
#include "interface.h"

// default is 0
// void	exit_status(int code)
// {
// 	if (code == SUCCESS)
// 		g_global_var.exit = SUCCESS;
// 	else if (code == FAIL)
// 		g_global_var.exit = FAIL;
// 	else
// 		g_global_var.exit = code + 128;
// }  g_global_var.exit = code % 256

void	print_stderr_no_exit(char *command, int code)
{
	g_global_var.exit = code % 256;
<<<<<<< HEAD
	printf("minishell: %s: %s\n", command, strerror(g_global_var.exit));
=======
	printf("minishell: %s: %s\n", command, (char *)strerror(g_global_var.exit));
>>>>>>> merge_test
}

void	print_stderr(char *error_print)
{
	perror(error_print);
	exit(1);
}

void	free_split(char ***split)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *split;
	while (tmp[i])
	{
		free(tmp[i]);
		++i;
	}
	free(tmp);
}
