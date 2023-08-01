/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:36:44 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/01 17:10:42 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

// compile 예시
// gcc ../libft/ft_strlen.c ../libft/ft_split.c extract_feature.c test.c ../libft/ft_strlcpy.c ../libft/ft_strncmp.c utility.c ../libft/ft_strdup.c

int	main(void)
{
	char		**vector;
	char		*tmp;
	t_file_info	*head1;
	t_file_info	*head2;

	tmp = ">>infile1 >infile2 <outfile1 <<outfile2 >infile3 <outfile3 >infile4 <<outfile4";
	vector = ft_split(tmp, ' ');
	head1 = extract_infile(vector, ft_strlen(tmp));
	while (head1->next)
	{
		printf("%s %d\n", head1->file_name, head1->write_mode);
		head1 = head1->next;
	}
	printf("\n\n\n");
	head2 = extract_outfile(vector, ft_strlen(tmp));
	while (head2->next)
	{
		printf("%s %d\n", head2->file_name, head2->write_mode);
		head2 = head2->next;
	}
	return (0);
}