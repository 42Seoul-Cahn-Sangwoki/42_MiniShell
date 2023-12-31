/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:48:03 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/25 20:47:16 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

char	*find_env(char *name)
{
	char		*res;
	t_env_node	*node;

	res = 0;
	if (name[0] == '?')
		res = ft_itoa(g_global_var.exit);
	if (name[0] == 0)
		res = ft_strdup("$");
	if (res == 0)
	{
		node = search_node_by_key(g_global_var.envp_head, name);
		if (node == 0)
			res = ft_strdup("");
		else
			res = ft_strdup(node->value);
	}
	free(name);
	return (res);
}

char	*extract_name(char *line, int *e_idx)
{
	int		i;
	char	*res;

	i = 0;
	*e_idx = *e_idx + 1;
	res = ft_strdup(&line[*e_idx]);
	while (res[i] && res[i] != '$' && res[i] != '\'' && res[i] != '\"')
	{
		if (res[i] == ' ' || (9 <= res[i] && res[i] <= 13))
			break ;
		if (res[i] == '/')
			break ;
		i++;
	}
	res[i] = 0;
	*e_idx = *e_idx + i;
	return (res);
}

int	find_next_quote(char *cmd, char quote, int i)
{
	while (cmd[i] && cmd[i] != quote)
		i++;
	if (cmd[i] == 0)
	{
		print_stderr_no_exit("quote is unbalance", FAIL);
		return (-100);
	}
	return (i);
}

char	*split_by_normal(char *cmd, int s_idx, int e_idx)
{
	char	tmp;
	char	*new_cmd;

	tmp = cmd[e_idx];
	cmd[e_idx] = 0;
	new_cmd = ft_strdup(&cmd[s_idx]);
	cmd[e_idx] = tmp;
	return (new_cmd);
}

char	**divided_quote(char *cmd)
{
	int		i;
	int		group_count;
	int		s_idx;
	char	**divided;

	i = 0;
	group_count = 0;
	divided = (char **)malloc(sizeof(char *) * (ft_strlen(cmd) + 1));
	while (cmd[i])
	{
		s_idx = i;
		while (cmd[i] && cmd[i] != '\'' && cmd[i] != '\"')
			i++;
		if (s_idx != i)
			divided[group_count++] = split_by_normal(cmd, s_idx, i);
		if (cmd[i] != 0)
		{
			s_idx = i;
			i = find_next_quote(cmd, cmd[i], i + 1) + 1;
			divided[group_count++] = split_by_normal(cmd, s_idx, i);
		}
	}
	divided[group_count] = 0;
	return (divided);
}
