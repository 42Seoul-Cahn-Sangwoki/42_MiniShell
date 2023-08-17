/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:57:58 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 17:19:25 by cahn             ###   ########.fr       */
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
    if (str[i] == '-')
    {
        minus = 1;
        ++i;
    }
    while (str[i])
    {
        if (num > (long long)LLONG_MAX / 10)
        {
            printf("numeric argument required\n");
            return (255);
        }
        num *= 10;
        if (num > (long long)LLONG_MAX - (str[i] - '0'))
        {
            printf("numeric argument required\n");
            return (255);
        }
        num += str[i] - '0';
        ++i;
    }
    if (minus)
    {
        if (num > ((long long)LLONG_MIN *  -1))
        {
            printf("numeric argument required\n");
            return (255);
        }
        return ((long long)256 + (long long)-1 * (num % 256));
    }
    return (num % 256);
}

void    ft_exit(char **parameter)
{
    // No_complete

    printf("exit\n");
    if (!parameter[1])
        g_global_var.exit = 0;
    else if (parameter[2])
        print_stderr(1);
}
