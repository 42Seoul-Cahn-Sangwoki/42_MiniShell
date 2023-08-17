/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:51:16 by cahn              #+#    #+#             */
/*   Updated: 2023/08/17 20:21:21 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../interface.h"
#include "execute.h"

static void print_export(char **sorted)
{
    int i;
    int j;
    int flag;

    i = 0;
    while (sorted[i])
    {
        printf("declare -x ");
        j = 0;
        flag = 0;
        while (sorted[i][j])
        {
            printf("%c", sorted[i][j]);
            if (sorted[i][j] == '=')
            {
                printf("\"");
                flag = 1;
            }
            ++j;
        }
        if (flag)
            printf("\"");
        printf("\n");
        ++i;
    }
}

static void export_no_parameter() // 문자열 오름차순으로 출력
{
    char    **for_sort;
    int     i;
    int     j;
    char    *tmp;

    for_sort = make_origin_form_envp(g_global_var.envp_head);
    i = 0;
    while (for_sort[i])
    {
        j = 0;
        while (for_sort[j] && for_sort[j + 1])
        {
            if (ft_strncmp(for_sort[j], for_sort[j + 1], COMPARE_NUMBER) > 0)
            {
                tmp = for_sort[j];
                for_sort[j] = for_sort[j + 1];
                for_sort[j + 1] = tmp;
            }
            ++j;
        }
        ++i;
    }
    print_export(for_sort);
    free_split(&for_sort);
}

static int  parameter_check(char *para)
{
    int i;

    if (ft_isalpha(para[0]) || para[0] == '_')
        return (1);
    i = 0;
    while (para[i])
    {
        if (!ft_isalnum(para[i]) && para[i] != '_')
            return (0);
        ++i;
    }
    return (1);
}


void    ft_export(char **parameter) // [0] next
{
    t_env_node  *find;
    t_env_node  *is_presence;

    if (!parameter[1])
    {
        export_no_parameter();
        return ;
    }
    if (!parameter_check(parameter[1]))
    {
        printf("export: not a valid identifier\n");
        return ;
    }
    if (parameter[1][0] == '_' && parameter[1][1] == 0)
        return ;
    find = get_node(parameter[1]);
    is_presence = search_node_by_key(g_global_var.envp_head, find->key);
    if (!is_presence)
        add_back(&g_global_var.envp_head, find);
    else if (find->value)
    {
        modify_env_value(is_presence, find->value);
        free_env_node(find);
    }
}