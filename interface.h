/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:51 by cahn              #+#    #+#             */
/*   Updated: 2023/08/24 16:36:38 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# include "libft/libft.h"
# include <signal.h>
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define WRITE_NEW 0
# define WRITE_BACK 1
# define READ -1
# define HERE_DOC -2
# define SUCCESS 0
# define FAIL 1

typedef struct s_file_info
{
	char				*file_name;
	int					write_mode;
	struct s_file_info	*next;
}	t_file_info;

typedef struct s_node
{
	char			**commands;
	t_file_info		*infile_head;
	t_file_info		*outfile_head;
}	t_node;

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
	struct s_env_node	*prev;
}	t_env_node;

typedef struct s_global
{
	t_env_node	*envp_head;
	int			exit;
}	t_global;

t_global	g_global_var;

void		execute(t_node *cmds, int length);
void		print_stderr(char *error_print);
void		print_stderr_no_exit(char *command, int code);
void		free_split(char ***split);
t_env_node	*copy_env_return_head(char **envp);
t_env_node	*get_node(const char *string);
t_env_node	*search_node_by_key(t_env_node *head, const char *key);
void		add_back(t_env_node **head, t_env_node *new);
void		modify_env_value(t_env_node *node, const char *str);
void		print_env_string_with_newline(t_env_node *node);
void		print_all_env(t_env_node *head);
void		delete_node(t_env_node **head, t_env_node *node);
int			return_env_list_size(t_env_node *head);
char		**make_origin_form_envp(t_env_node *head);
void		free_env_node(t_env_node *node);
void		free_env_list(t_env_node **head);
void		free_token(t_node *token, int length);

#endif