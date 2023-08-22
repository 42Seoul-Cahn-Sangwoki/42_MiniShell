/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:45:14 by cahn              #+#    #+#             */
/*   Updated: 2023/08/22 13:50:36 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

#define RETURN_ERROR 1
#define RETURN_NORMAL 0
#define COMPARE_NUMBER 2147483647

typedef struct s_process_manage
{
    int     *child_pid_array;
    int     **pipe_array;
}   t_process_manage;

// memo : 파이프라인과 리다이렉션이 동시에 있는경우, 리다이렉션이 우선임.(파이프라인 처리할 필요없음)
// 리다이렉션이 여러개인 경우 마지막 하나만 처리
// 히어독이 최우선적으로 처리된다. 부모에서 먼저 처리하기.
// 부모에서 각 파일명을 바꾸고 써주기.

// 전역변수는 구조체
// 빌트인함수 구현.
// cd의 인자가 하나인경우
// 빌트인 함수를 사용한 경우 / cd

int	    check_and_create_file_by_write(char *file_name);
int	    return_input_fd(t_file_info *head);
int	    return_output_fd(t_file_info *head);
void    token_processing(t_node *token, int **pipe, int index, int length);
void	parent_processing(t_process_manage *pm, t_node *head, int length);
void	allocate_process_manage(t_process_manage *pm, int length);
char    *return_tmpfile_name_by_here_document(char *end_string);
char	*ft_ultoa(unsigned long long n);
char	*find_path();
void	find_execute_file(char **commands, char *path);
char    *make_no_overlap_tmpfile(void);
void    create_heredoc_file(t_node *cmds, int length);
void    delete_tmp_file(t_node *cmds, int length);

int     update_pwd();
int	    is_built_in(char *command);
int     ft_cd(char **parameter);
int     ft_echo(char **parameter);
int     ft_pwd(char **parameter);
int     ft_export(char **parameter);
int     ft_unset(char **parameter);
int     ft_env(char **parameter);
int     ft_exit(char **parameter);
int	    execute_built_in(char *command, char **parameter);
int     set_exit_status(int code, char *perror_cmd, char *perror_file);


#endif