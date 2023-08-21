/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:19:11 by cahn              #+#    #+#             */
/*   Updated: 2023/08/21 20:05:46 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

int update_pwd()
{
    char        *cur_path;
    t_env_node  *pwd;
    t_env_node  *old_pwd;

    cur_path = (char *)malloc(PATH_MAX + 1);
    if (!cur_path)
    {
        g_global_var.exit = 12;
        return (g_global_var.exit);
    }
    if (!getcwd(cur_path, PATH_MAX))
    {
        g_global_var.exit = 34;
        free(cur_path);
        return (g_global_var.exit);
    }
    pwd = search_node_by_key(g_global_var.envp_head, "PWD");
    old_pwd = search_node_by_key(g_global_var.envp_head, "OLDPWD");
    if (!pwd)
    {
        g_global_var.exit = 1;
        printf("no $PWD\n");
        return (g_global_var.exit);
    }
    if (!old_pwd)
    {
        g_global_var.exit = 1;
        printf("no $OLDPWD\n");
        return (g_global_var.exit);
    }
    modify_env_value(old_pwd, pwd->value);
    modify_env_value(pwd, cur_path);
    return (0);
}

char    *get_home_free_origin(char *origin)
{
    t_env_node  *find;

    find = search_node_by_key(g_global_var.envp_head, "HOME");
    if (!find)
    {
        printf("No $home : no implement\n");
        return (origin);
    }
    if (origin != NULL)
        free(origin);
    return (ft_strdup(find->value));
}

char    *get_parent_free_origin(char *origin)
{
    char    *parent;
    char    *find;

    find = ft_strrchr(origin, '/');
    *find = 0;
    if (*origin == 0)
    {
        free(origin);
        return (ft_strdup("/"));
    }
    parent = ft_strdup(origin);
    free(origin);
    return (parent);
}

char    *join_path_free_origin(char *origin, char *new_path)
{
    char    *join;
    char    *join2;

    join = ft_strjoin(origin, "/");
    join2 = ft_strjoin(join, new_path);
    free(join);
    free(origin);
    return (join2);
}

char    *get_absolute_path()
{
    char    *buffer;

    buffer = (char *)malloc(sizeof(char) * (PATH_MAX + 1));
    if (!buffer)
    {
        g_global_var.exit = 12;
        return (NULL);
    }
    if (!getcwd(buffer, PATH_MAX + 1))
    {
        g_global_var.exit = 34;
        free(buffer);
        return (NULL);
    }
    return (buffer);
}

int ft_cd(char **parameter) // 맨 첫 번째 인자만.
{
    char    *cd_path;
    char    *complete;
    char    **split;
    int     i;

    cd_path = parameter[1];
    if (!cd_path)
    {
        complete = get_home_free_origin(NULL);
        if (chdir(complete))
            return (set_exit_status(1, ft_strjoin("cd: ", parameter[1]), "No such file or directory"));
        update_pwd();
        free(complete);
        return (set_exit_status(0, NULL, NULL));
    }
    if (cd_path[0] == '/')
        complete = ft_strdup("/");
    else
        complete = get_absolute_path();
    split = ft_split(cd_path, '/');
    if (!split)
        return (set_exit_status(1, ft_strjoin("cd: ", parameter[1]), strerror(12)));
    i = 0;
    while (split[i])
    {
        if (!ft_strncmp(split[i], "..", COMPARE_NUMBER))
            complete = get_parent_free_origin(complete);
        else if (!ft_strncmp(split[i], "~", COMPARE_NUMBER))
            complete = get_home_free_origin(complete);
        else if (ft_strncmp(split[i], ".", COMPARE_NUMBER))
            complete = join_path_free_origin(complete, split[i]);
        ++i;
    }
    if (chdir(complete))
        return (set_exit_status(1, ft_strjoin("cd: ", parameter[1]), "No such file or directory"));
    update_pwd();
    return (set_exit_status(0, NULL, NULL));

}