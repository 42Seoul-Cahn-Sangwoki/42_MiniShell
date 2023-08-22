/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:39:26 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/22 20:21:50 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

int	is_file(char *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strncmp(cmd, ">>", 2) == 0 || ft_strncmp(cmd, "<<", 2) == 0)
		ret = 2;
	else if (ft_strncmp(cmd, ">", 1) == 0 || ft_strncmp(cmd, "<", 1) == 0)
		ret = 1;
	if (ret != 0 && cmd[ret] != 0)
		return (0);
	return (ret);
}

void	normalize_file(char **join_file)
{
	int		i;
	int		next_is_name;

	next_is_name = FALSE;
	if (is_file(join_file[0]))
		next_is_name = TRUE;
	i = 1;
	while (join_file[i])
	{
		if (next_is_name == TRUE)
		{
			join_file[i - 1] = append_commend(join_file[i - 1], join_file[i]);
			join_file[i] = ft_strdup(" ");
			next_is_name = FALSE;
		}
		else if (is_file(join_file[i]))
			next_is_name = TRUE;
		i++;
	}
}

// handle_quote
// token->commands = extract_command(vector, ft_strlen(norm_command));
int	tokenizer(t_node *token, char *command)
{
	char	**vector;
	int		error;

	error = 0;
	vector = ft_split_group(command, TRUE, TRUE);
	normalize_file(vector);
	token->commands = extract_command(vector, ft_strlen(command));
	execute_shell(&(token->commands));
	handle_quote(token->commands);
	token->infile_head = extract_infile(vector, &error);
	token->outfile_head = extract_outfile(vector, &error);
	free_split(&vector);
	free(command);
	return (error);
}

t_node	*token2corpus(int pipex_counter, char *line, int *error)
{
	char	**corpus;
	int		i;
	t_node	*token;

	corpus = ft_split(line, '|');
	if (error_handling(corpus) == TRUE)
		return (FALSE);
	token = init_token(pipex_counter);
	i = 0;
	while (i < pipex_counter + 1)
	{
		if (tokenizer(token + i, corpus[i]) == 1)
			*error = 1;
		i++;
	}
	free(corpus);
	return (token);
}

t_node	*command_line(char *line, int *length)
{
	t_node	*token;
	int		pipex_counter;
	int		error;

	error_pipe(line);
	pipex_counter = pipex_count(line);
	*length = pipex_counter + 1;
	error = 0;
	token = token2corpus(pipex_counter, line, &error);
	if (error)
	{
		// free_token
		return (FALSE);
	}
	if (token == FALSE)
		return (FALSE);
	return (token);
}
