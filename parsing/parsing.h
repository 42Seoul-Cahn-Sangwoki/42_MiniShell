/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:18:02 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/13 20:16:58 by sangwoki         ###   ########.fr       */
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
t_node		**token2corpus(int pipex_counter, char *line, char **envp);
t_node		**command_line(char *line, int *length, char **envp);
char    	**normalize_file(char **cmd);
int	        is_file(char *cmd);
t_node		*tokenizer(char *norm_command, char **envp);

// parsing_error.c
int			error_handling(char **corpus);
int			error_symbol(char *command);
void		error_pipe(char *cmd);
// parsing_free.c
void		free_corpus(char **curpus);

// utitlity.c
int			normalize_redirect(char *dup, char *command, int *is_mode);
void		ft_push_back(t_file_info **head, t_file_info **node);
t_file_info	*get_info(char *file_name, int write_mode);

// extract_feature.c
char		**extract_command(char **command, int length);
t_file_info	*extract_infile(char **command);
t_file_info	*extract_outfile(char **command);

// execute_dollar.c
char		*find_env(char **envp, char *name);
char		*extract_name(char *line, int *e_idx);

// handler_symbol.c
void		handle_quote(char **cmd, char **envp);
int			find_next_quote(char *cmd, char quote, int i);
char		*split_by_normal(char *cmd, int s_idx, int e_idx);
char		**divided_quote(char *cmd);
char		*exclude_quote(char *cmd, char quote);
char		*change_commed(char **envp, char *cmd, char value);
char		*append_commend(char *cmd, char *tmp);
char		*ft_merge(char **divided);

// ft_split_group.c
int			exclude_whitespace(char *str, int is_whitespace, int s_idx);
size_t		mk_branch_group(char *str, int is_white, int is_quote);
char		*mk_leaf_group(char *str, size_t len);
size_t		mk_tree_group(char *str, int flag, size_t size, char **branch);
char		**ft_split_group(char *s, int is_whitespace, int is_quote);

#endif