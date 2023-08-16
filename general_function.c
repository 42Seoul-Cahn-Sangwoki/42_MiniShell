
#include "interface.h"

// default is 0
void	exit_status(int code)
{
	if (code == SUCCESS)
		g_global_var.exit = SUCCESS;
	else if (code == FAIL)
		g_global_var.exit = FAIL;
	else
		g_global_var.exit = code + 128;
}

void	non_valid_error(char *error_print)
{
	int	len;

	len = ft_strlen(error_print);
	write(1, error_print, len);
	write(1, " is not valid.\n", 16);
	exit(1);
	exit_status(FAIL);
}

void	print_stderr(char *error_print)
{
	perror(error_print);
	exit(1);
	exit_status(FAIL);
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

char	**copy_env(char **envp)
{
	char	**new_envp;
	int		i;

	i = 0;
	while (envp[i])
		++i;
	new_envp = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_envp)
		print_stderr("Malloc");
	i = 0;
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		if (!new_envp[i])
			print_stderr("Malloc");
		++i;
	}
	return (new_envp);
}

