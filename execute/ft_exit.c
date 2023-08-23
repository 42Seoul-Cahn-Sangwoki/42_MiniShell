/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:57:58 by cahn              #+#    #+#             */
/*   Updated: 2023/08/23 14:48:28 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static int	is_numeric_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		++i;
	}
	return (1);
}

static long long	ft_atol_make_number(char *num_str, int i, \
					unsigned long long num)
{
	while (num_str[i])
	{
		if (num > (long long)LLONG_MAX / 10)
		{
			g_global_var.exit = 1;
			return (255);
		}
		num *= 10;
		if (num > (unsigned long long)((long long)LLONG_MAX - \
				(num_str[i] - '0')))
		{
			g_global_var.exit = 1;
			return (255);
		}
		num += num_str[i] - '0';
		++i;
	}
	return (num);
}

static long long	ft_atol_for_exit(char *str)
{
	int					minus;
	int					i;
	unsigned long long	num;

	i = 0;
	minus = 0;
	num = 0;
	if (str[i] == '-')
	{
		minus = 1;
		++i;
	}
	num = ft_atol_make_number(str, i, num);
	if (minus)
	{
		if ((long long)num * -1 > ((long long)LLONG_MIN))
		{
			g_global_var.exit = 1;
			return (255);
		}
		return ((long long)256 + (long long)-1 * (num % 256));
	}
	return (num % 256);
}

int	set_exit_status(int code, char *perror_cmd, char *error_message)
{
	g_global_var.exit = code % 256;
	if (perror_cmd != NULL)
	{
		printf("%s", perror_cmd);
		free(perror_cmd);
	}
	if (error_message != NULL)
		printf(": %s\n", error_message);
	return (g_global_var.exit);
}

int	ft_exit(char **parameter, int one)
{
	int	exit_code;

	g_global_var.exit = 0;
	if (!parameter[1])
	{
		if (one)
			printf("exit\n");
		exit(0);
	}
	else if (parameter[1] && parameter[2])
		return (set_exit_status(1, ft_strdup("exit"), "too many arguments"));
	else if (!is_numeric_string(parameter[1]))
	{
		set_exit_status(255, ft_strdup("exit"), "numeric argument requied");
		if (one)
			printf("exit\n");
		exit(255);
	}
	exit_code = ft_atol_for_exit(parameter[1]);
	if (g_global_var.exit)
		set_exit_status(g_global_var.exit, ft_strjoin("exit: ", parameter[1]), \
				"numeric argument required");
	if (one)
		printf("exit\n");
	exit(exit_code);
}
