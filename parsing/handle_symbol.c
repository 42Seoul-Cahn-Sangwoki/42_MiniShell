/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_symbol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:34:26 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/23 12:53:03 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

// 1. split by quote: cmd[next_quote]=' '-> split
// 2. change each group considering $ and quote rule.
// 3. merge group
void	handle_quote(char **cmd, int is_change)
{
	char	**divided;
	char	*ex_quote;
	char	quote;
	int		i;
	int		j;

	if (cmd == 0)
		return ;
	i = -1;
	while (cmd[++i])
	{
		j = 0;
		divided = divided_quote(cmd[i]);
		while (divided[j])
		{
			quote = divided[j][0];
			ex_quote = exclude_quote(divided[j], quote);
			if (is_change)
				ex_quote = change_commed(ex_quote, quote);
			divided[j] = ex_quote;
			j++;
		}
		free(cmd[i]);
		cmd[i] = ft_merge(divided);
	}
}

// 2. change each group considering $ and quote rule.
// consequtive $ is error.
// [open_quote, close_quote] => each quote delete first
// 1) if double quote or noting: 
// 2) if single quote: change
char	*exclude_quote(char *cmd, char quote)
{
	char	*ex_quote;

	if (quote != '\"' && quote != '\'')
		return (cmd);
	ex_quote = ft_strdup(&cmd[1]);
	ex_quote[ft_strlen(ex_quote) - 1] = 0;
	free(cmd);
	return (ex_quote);
}

// about command: gohome$HOME$USER, "  $HOME", " $", "    $?    "
char	*change_commed(char *cmd, char value)
{
	char	*join_cmd;
	char	*tmp;
	int		i;
	int		s_idx;

	if (value == '\'')
		return (cmd);
	join_cmd = ft_strdup("");
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '$')
			tmp = find_env(extract_name(cmd, &i));
		else
		{
			s_idx = i;
			while (cmd[i] && cmd[i] != '$')
				i++;
			tmp = change_commend_utility(cmd, value, i, s_idx);
		}
		join_cmd = append_commend(join_cmd, tmp);
	}
	free(cmd);
	return (join_cmd);
}

// 3. join with dollar
char	*append_commend(char *cmd, char *tmp)
{
	char	*result;

	result = ft_strjoin(cmd, tmp);
	free(cmd);
	free(tmp);
	return (result);
}

char	*ft_merge(char **divided)
{
	int		i;
	char	*res;
	char	*tmp;

	res = ft_strdup("");
	i = 0;
	while (divided[i])
	{
		tmp = ft_strjoin(res, divided[i]);
		free(res);
		res = tmp;
		i++;
	}
	free_split(&divided);
	return (res);
}
