/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:26:12 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/09 17:40:56 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		idx;

	ch = c;
	idx = 0;
	while (s[idx])
	{
		if (s[idx] == ch)
			return ((char *)(s + idx));
		idx++;
	}
	if (ch == 0)
		return ((char *)(s + idx));
	return (0);
}
