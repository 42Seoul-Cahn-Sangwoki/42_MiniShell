/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:49:34 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/13 20:43:49 by sangwoki         ###   ########.fr       */
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
	if (ret != 0 && cmd[ret] == '$')
		print_stderr("$ can't be fd");
	if (ret != 0 && cmd[ret] != 0)
		return (0);
	return (ret);
}

char	**normalize_file(char **join_file)
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
			if (join_file[i][0] == '\'' || join_file[i][0] == '\"')
				print_stderr("don't have fd");
			join_file[i - 1] = append_commend(join_file[i - 1], join_file[i]);
			join_file[i] = ft_strdup(" ");
			next_is_name = FALSE;
		}
		else if (is_file(join_file[i]))
			next_is_name = TRUE;
		i++;
	}
	if (next_is_name == TRUE)
		print_stderr("dont't have fd");
	return (join_file);
}

// handle_quote
// token->commands = extract_command(vector, ft_strlen(norm_command));
t_node	*tokenizer(char *command, char **envp)
{
	char	**vector;
	t_node	*token;

	token = (t_node *)malloc(sizeof(t_node));
	vector = ft_split_group(command, TRUE, TRUE);
	token->commands = extract_command(vector, ft_strlen(command));
	handle_quote(token->commands, envp);
	vector = normalize_file(vector);
	token->infile_head = extract_infile(vector);
	token->outfile_head = extract_outfile(vector);
	free_split(&vector);
	free(command);
	return (token);
}

t_node	**token2corpus(int pipex_counter, char *line, char **envp)
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
		token[i] = tokenizer(corpus[i], envp);
		i++;
	}
	free_corpus(corpus);
	return (token);
}

t_node	**command_line(char *line, int *length, char **envp)
{
	t_node	**token;
	int		pipex_counter;

	error_pipe(line);
	pipex_counter = pipex_count(line);
	*length = pipex_counter + 1;
	token = token2corpus(pipex_counter, line, envp);
	if (token == FALSE)
		return (FALSE);
	return (token);
}
