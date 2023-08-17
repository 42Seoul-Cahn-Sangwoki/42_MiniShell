/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 23:37:17 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/15 15:24:26 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

void	file_info_free(t_file_info **head)
{
	t_file_info	*tmp;

	if ((*head) == 0)
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		free((*head)->file_name);
		free((*head));
		(*head) = tmp;
	}
}

void	token_free(t_node ***token)
{
	int			i;

	i = 0;
	while ((*token)[i])
	{
		free_split(&(*token)[i]->commands);
		file_info_free(&((*token)[i]->infile_head));
		file_info_free(&((*token)[i]->outfile_head));
		free((*token)[i]);
		i++;
	}
	free((*token));
}
