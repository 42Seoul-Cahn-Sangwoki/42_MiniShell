/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:19:11 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 16:59:07 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

// cd => home
// cd . => no change
// cd ~ => home
// cd .. => parent

void    update_pwd()
{
    char        *cur_path;
    t_env_node  *pwd;
    t_env_node  *old_pwd;

    cur_path = (char *)malloc(PATH_MAX + 1);
    if (!cur_path)
    {
        print_stderr_no_exit("cd", 12);
        return ;
    }
    if (!getcwd(cur_path, PATH_MAX))
    {
        print_stderr("Getcwd");

    }
    pwd = search_node_by_key(g_global_var.envp_head, "PWD");
    old_pwd = search_node_by_key(g_global_var.envp_head, "OLDPWD");
    if (!pwd)
    {
        printf("no $PWD\n");
        return ;
    }
    if (!old_pwd)
    {
        printf("no $OLDPWD\n");
        return ;
    }
    modify_env_value(old_pwd, pwd->value);
    modify_env_value(pwd, cur_path);
}

int    go_home()
{
    t_env_node  *home;

    home = search_node_by_key(g_global_var.envp_head, "HOME");
    if (!home)
    {
        printf("no $HOME\n");
        return (0);
    }
    if (chdir(home->value))
    {
        print_stderr_no_exit("cd", 1);
        return (1);
    }
    return (1);
}

int    go_parent()
{
    char    *cur_path;
    char    *last;

    cur_path = (char *)malloc(PATH_MAX + 1);
    if (!cur_path)
    {
        print_stderr_no_exit("cd", 12);
        return (0);
    }
    if (!getcwd(cur_path, PATH_MAX))
    {
        print_stderr_no_exit("cd", 12);
        free(cur_path);
        return (0);
    }
    last = ft_strrchr(cur_path, '/');
    *(last + 1) = 0;
    if (chdir(cur_path))
    {
        print_stderr_no_exit("cd", 1);
        free(cur_path);
        return (0);
    }    
    free(cur_path);
    return (1);
}

void    ft_cd(char *path) // 맨 첫 번째 인자만.
{
    char    **split;
    int     i;

    if (!path)
    {
        if (!go_home())
            return ;
        update_pwd();
        g_global_var.exit = 0;
        return ;
    }
    if (path[0] == '/')
        if (chdir("/"))
        {
            print_stderr_no_exit("cd", 1);
            return ;
        }
    split = ft_split(path, '/');
    if (!split)
    {
        print_stderr_no_exit("cd_split", 12);
        return ;
    }
    i = 0;
    while (split[i])
    {
        if (!ft_strncmp(split[i], ".", ft_strlen(split[i])))
            continue;
        if (!ft_strncmp(split[i], "..", ft_strlen(split[i])))
            if (!go_parent())
            {
                free_split(&split);
                return ;
            }
        if (!ft_strncmp(split[i], "~", ft_strlen(split[i])))
            if (!go_home())
            {
                free_split(&split);
                return ;
            }
        ++i;
    }
    free_split(&split);
    update_pwd();
}