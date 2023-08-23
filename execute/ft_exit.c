/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:57:58 by cahn              #+#    #+#             */
/*   Updated: 2023/08/21 20:19:35 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static int  is_numeric_string(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        ++i;
    }
    return (1);
}

static long long ft_atol_for_exit(char *str)
{
    int                 minus;
    int                 i;
    unsigned long long  num;

    i = 0;
    minus = 0;
    num = 0;
    if (str[i] == '-')
    {
        minus = 1;
        ++i;
    }
    while (str[i])
    {
        if (num > (long long)LLONG_MAX / 10)
        {
            g_global_var.exit = 1;
            return (255);
        }
        num *= 10;
        if (num > (unsigned long long)((long long)LLONG_MAX - (str[i] - '0')))
        {
            g_global_var.exit = 1;
            return (255);
        }
        num += str[i] - '0';
        ++i;
    }
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

int set_exit_status(int code, char *perror_cmd, char *error_message)
{
    g_global_var.exit = code % 256;
    if (perror_cmd != NULL)
        printf("%s", perror_cmd);
    if (error_message != NULL)
        printf(": %s\n", error_message);
    free(perror_cmd);
    return (g_global_var.exit);
}

void    down_shell_level()
{
    t_env_node  *node;
    int         level;
    char        *new_level;

    node = search_node_by_key(g_global_var.envp_head, "SHLVL");
    level = ft_atoi(node->value);
    level--;
    new_level = ft_itoa(level);
    modify_env_value(node, new_level);
    free(new_level);
}

int ft_exit(char **parameter)
{
    int exit_code;

    g_global_var.exit = 0;
    if (!parameter[1])
    {
        down_shell_level();
        printf("exit\n");
        exit(0);
    }
    else if (parameter[1] && parameter[2])
        return (set_exit_status(1, ft_strdup("exit"), "too many arguments"));
    else if (!is_numeric_string(parameter[1]))
    {
        set_exit_status(255, ft_strdup("exit"), "numeric argument requied");
        down_shell_level();
        printf("exit\n");
        exit(255);
    }
    exit_code = ft_atol_for_exit(parameter[1]);
    if (g_global_var.exit)
        set_exit_status(g_global_var.exit, ft_strjoin("exit: ", parameter[1]), "numeric argument required");
    down_shell_level();
    printf("exit\n");
    exit(exit_code);
}
