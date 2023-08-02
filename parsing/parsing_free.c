/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:02:03 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/01 14:39:34 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void	free_corpus(char **curpus)
{
	int	i;

	i = 0;
	while (curpus[i])
	{
		free(curpus[i]);
		i++;
	}
	free(curpus);
}
