
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

void	print_stderr(int error_code)
{
	perror(strerror(error_code));
	exit(error_code);
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
