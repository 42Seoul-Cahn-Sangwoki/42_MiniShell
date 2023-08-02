/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:18:02 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/02 22:18:54 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <termios.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1

# include"../interface.h"

// preprocessing.c
int			is_whitespace(char *line);
int			pipex_count(char *line);
t_node		**init_token(int pipex_counter);

// tokenizer.c
t_node		**token2corpus(int pipex_counter, char *line);
t_node		**command_line(char *line, int *length);
// char	**tokenizer(int str, int end, t_node *token);

// parsing_error.c
int			error_handling(char **corpus);
int			error_symbol(char *command);
int			error_bracket(char *command);
// parsing_free.c
void		free_corpus(char **curpus);

// utitlity.c
int         normalize_redirect(char *dup, char *command, int *is_mode);
void		ft_push_back(t_file_info **head, t_file_info **node);
t_file_info	*get_info(char *file_name, int write_mode);

// extract_feature.c
char		**extract_command(char **command, int length);
t_file_info	*extract_infile(char **command);
t_file_info	*extract_outfile(char **command);

#endif