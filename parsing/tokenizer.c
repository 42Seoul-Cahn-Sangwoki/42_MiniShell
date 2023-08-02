/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:49:34 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/01 20:18:15 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

t_node	*tokenizer(char *norm_command)
{
	char	**vector;
	t_node	*token;

	token = (t_node *)malloc(sizeof(t_node));
	vector = ft_split(norm_command, ' ');
	token->commands = extract_command(vector, ft_strlen(norm_command));
	token->infile_head = extract_infile(vector);
	token->outfile_head = extract_outfile(vector);
	free_corpus(vector);
	free(norm_command);
	return (token);
}

char	*normalize(char *command)
{
	char	*dup;
	int		i;
	int		j;
	int		is_mode;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(command) * 2));
	i = 0;
	j = 0;
	while (command[i])
	{
		while (command[i] && command[i] == ' ')
			i++;
		is_mode = normalize_redirect(&dup[j], &command[i]);
		while (command[i] && command[i] != ' ' && is_mode == 0)
		{
			ft_strlcpy(&dup[j], &command[i], 2);
			j++;
			i++;
		}
		dup[j + is_mode] = ' ';
		j = j + is_mode + 1;
		i = i + is_mode;
	}
	return (dup);
}

t_node	**token2corpus(int pipex_counter, char *line)
{
	char	**corpus;
	int		i;
	t_node	**token;

	corpus = ft_split(line, '|');
	if (error_handling(corpus) == TRUE)
		return (FALSE);
	token = init_token(pipex_counter);
	i = 0;
	while (i < pipex_counter + 1)
	{
		// (', ") handle code...
		// handle_quote(corpus[i])
		token[i] = tokenizer(normalize(corpus[i]));
		i++;
	}
	free_corpus(corpus);
	return (token);
}

t_node	**command_line(char *line, int *length)
{
	t_node	**token;
	int		pipex_counter;

	pipex_counter = pipex_count(line);
	*length = pipex_counter + 1;
	token = token2corpus(pipex_counter, line);
	if (token == FALSE)
		return (FALSE);
	return (token);
}
