/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:31:13 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/25 20:48:19 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <termios.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1

# include"../interface.h"

int			is_whitespace(char *line);
int			pipex_count(char *line);
t_node		*init_token(int pipex_counter);

t_node		*token2corpus(int *pipex_counter, char *line, int *error);
t_node		*command_line(char *line, int *length);
void		normalize_file(char **cmd);
int			is_file(char *cmd, int is_token);
int			tokenizer(t_node *token, char *command);

int			error_handling(char **corpus);
int			error_symbol(char *command);
void		error_pipe(char *cmd, int *error);
void		error_quote_pipe(char *cmd, int *error);
int			exclude_whitespace_quote(char *cmd, int s_idx, int *error);

int			normalize_redirect(char *dup, char *command, int *is_mode);
void		ft_push_back(t_file_info **head, t_file_info **node);
t_file_info	*get_info(char *file_name, int write_mode);
char		*change_commend_utility(char *cmd, char value, int i, int s_idx);
char		*file_name_quote(char *file_name, int *error);

char		**extract_command(char **command, int length);
t_file_info	*extract_outfile(char **command, int *error);
t_file_info	*extract_infile(char **command, int *error);
char		*allocate_tmp(int length);

char		*find_env(char *name);
char		*extract_name(char *line, int *e_idx);

void		handle_quote(char **cmd, int is_change);
int			find_next_quote(char *cmd, char quote, int i);
char		*split_by_normal(char *cmd, int s_idx, int e_idx);
char		**divided_quote(char *cmd);
char		*exclude_quote(char *cmd, char quote);
char		*change_commed(char *cmd, char value);
char		*append_commend(char *cmd, char *tmp);
char		*ft_merge(char **divided);

int			exclude_whitespace(char *str, int is_whitespace, int s_idx);
size_t		mk_branch_group(char *str, int is_white);
char		*mk_leaf_group(char *str, size_t len);
size_t		mk_tree_group(char *str, int flag, size_t size, char **branch);
char		**ft_split_group(char *s, int is_whitespace, int is_quote);

void		file_info_free(t_file_info **head);
void		token_free(t_node ***token);
int			exclue_redirect(char *str, int i);

void		init_env(int argc, char *argv[], char *envp[]);
void		valid_command_line(char *line);
void		execute_shell(char ***command);

char		**ft_split_pipe(char *s, int *size);
int			mk_tree_pipe(char *str, int size, char **branch);
int			mk_branch_pipe(char *str);
int			exclude_pipe(char *str, int s_idx);
#endif