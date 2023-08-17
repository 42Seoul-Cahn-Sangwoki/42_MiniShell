/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:17:59 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 13:34:57 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

void    ft_echo(char **parameter)
{
    int i;

    i = 1;
    while (parameter[i])
    {
        printf("%s ", parameter[i]);
        ++i;
    }
    printf("\n");
}