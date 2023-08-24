/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:45:14 by cahn              #+#    #+#             */
/*   Updated: 2023/08/24 21:26:25 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# define RETURN_ERROR 1
# define RETURN_NORMAL 0
# define COMPARE_NUMBER 2147483647

typedef struct s_process_manage
{
	int		*child_pid_array;
	int		**pipe_array;
}	t_process_manage;

int		check_and_create_file_by_write(char *file_name);
int		return_input_fd(t_file_info *head, int one);
int		return_output_fd(t_file_info *head, int one);
void	token_processing(t_node *token, int **pipe, int index, int length);
void	parent_processing(t_process_manage *pm, t_node *head, int length);
void	allocate_process_manage(t_process_manage *pm, int length);
void	change_tmpfile_name_by_here_document(char *end_string, char *tmp_file);
char	*ft_ultoa(unsigned long long n);
char	*find_path(void);
int		find_execute_file(char **commands, char *path);
char	*make_no_overlap_tmpfile(void);
int		create_heredoc_file(t_node *cmds, int length);
void	delete_tmp_file(t_node *cmds, int length);
int		is_valid_execute_file(char	*commands, char *path);
int		update_pwd(void);
int		is_built_in(char *command);
int		ft_cd(char **parameter);
int		ft_echo(char **parameter);
int		ft_pwd(char **parameter);
int		ft_export(char **parameter);
int		ft_unset(char **parameter);
int		ft_env(char **parameter);
int		ft_exit(char **parameter, int one);
int		execute_built_in(char *command, char **parameter, int one);
int		set_exit_status(int code, char *perror_cmd, char *perror_file);
char	*get_absolute_path(void);
char	*get_home_free_origin(char *origin);
void	close_all_pipe(int **pipe_array, int length);
#endif