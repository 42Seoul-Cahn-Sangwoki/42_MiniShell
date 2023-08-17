/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:56:32 by sangwoki          #+#    #+#             */
/*   Updated: 2022/11/11 12:13:50 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while ((s1[i] || s2[i]) && ret == 0 && i < n)
	{
		ret = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (ret != 0)
			return (ret);
		i++;
	}
	return (ret);
}
