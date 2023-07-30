/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:37:47 by cahn              #+#    #+#             */
/*   Updated: 2023/07/30 17:38:52 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "interface.h"

void	non_valid_error(char *error_print)
{
	int	len;

	len = ft_strlen(error_print);
	write(1, error_print, len);
	write(1, " is not valid.\n", 16);
	exit(1);
}

void	print_stderr(char *error_print)
{
	perror(error_print);
	exit(1);
}
