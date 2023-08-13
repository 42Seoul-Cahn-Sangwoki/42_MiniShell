/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:09:48 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/13 13:10:10 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"signal.h"

void	term_echo_on(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	term_echo_off(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}