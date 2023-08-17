/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:27:53 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/11 13:32:32 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	mark;
	size_t	s_index;
	size_t	f_index;
	size_t	length;

	length = ft_strlen((const char *)to_find);
	if (length == 0)
		return ((char *)str);
	s_index = 0;
	while (s_index < len && str[s_index])
	{
		mark = s_index;
		f_index = 0;
		while (s_index < len && str[s_index] && to_find[f_index])
		{
			if (str[s_index] != to_find[f_index])
				break ;
			s_index++;
			f_index++;
		}
		if (f_index == length)
			return ((char *)&str[mark]);
		s_index = mark + 1;
	}
	return (0);
}
