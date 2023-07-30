/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:13:23 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/09 20:01:14 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	idx;
	char	*last;

	ch = c;
	idx = 0;
	last = 0;
	while (s[idx])
	{
		if (s[idx] == ch)
			last = ((char *)(s + idx));
		idx++;
	}
	if (last)
		return (last);
	if (ch == 0)
		return ((char *)(s + idx));
	return (0);
}
