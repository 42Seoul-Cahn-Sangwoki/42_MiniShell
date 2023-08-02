/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:45:14 by cahn              #+#    #+#             */
/*   Updated: 2023/07/31 20:46:17 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include <fcntl.h>

#define RETURN_ERROR 1
#define RETURN_NORMAL 1

typedef struct s_process_manage
{
    int *child_pid_array;
    int **pipe_array;
}   t_process_manage;

// memo : 파이프라인과 리다이렉션이 동시에 있는경우, 리다이렉션이 우선임.(파이프라인 처리할 필요없음)
// 리다이렉션이 여러개인 경우 마지막 하나만 처리

void	allocate_process_manage(t_process_manage *pm, int length);
char	*find_path(char **envp);
int	    check_and_create_file_by_write(char *file_name);


#endif