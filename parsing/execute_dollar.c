/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:48:03 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/14 16:12:18 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

char	*find_env(char **envp, char *name)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	if (name[0] == '?')
		res = ft_itoa(g_global_var.exit);
	if (name[0] == 0)
		res = ft_strdup("$");
	while (res == 0 && envp[i] != 0)
	{
		if (ft_strncmp(name, envp[i], ft_strlen(name)) == 0)
			res = ft_strdup(&envp[i][ft_strlen(name) + 1]);
		++i;
	}
	if (res == 0)
		res = ft_strdup("");
	free(name);
	return (res);
}

// if i == 0 means "$"
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
		print_stderr("quote is unbalance");
	return (i);
}

// 1. split: [s_idx, e_idx)
// 1) split by normal: cmd[e_idx] = 0 -> ft_strdup -> resotre
// 2) split by quote: cmd[next_quote] = 0 -> ft_strdup
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
	divided = (char **)malloc(sizeof(char *) * ft_strlen(cmd));
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
