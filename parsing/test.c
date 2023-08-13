/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:36:44 by sangwoki          #+#    #+#             */
/*   Updated: 2023/08/13 20:44:59 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"parsing.h"

// compile 예시
// gcc ../libft/ft_strlen.c ../libft/ft_split.c extract_feature.c test.c ../libft/ft_strlcpy.c ../libft/ft_strncmp.c utility.c ../libft/ft_strdup.c

int	main(int argc, char *argv[], char *envp[])
{
	char		**vector;
	char		*tmp;
	char		*quote;
	t_file_info	*head1;
	t_file_info	*head2;
	char		**result;
	int			i;

	tmp = ">>         outfile1 >          outfile2 <     infile1 \'<<infile2 >outfile3\' <intfile3 >outfile4 <<outfile4 $     $? GOHOME $HOME";
	vector = ft_split_group(tmp, TRUE, TRUE);
	vector = normalize_file(vector);

	i = 0;
	while (vector[i])
	{
		printf("%s\n", vector[i]);
		i++;
	}
	head1 = extract_infile(vector);
	while (head1->next)
	{
		printf("%s %d\n", head1->file_name, head1->write_mode);
		head1 = head1->next;
	}
	printf("\n\n\n");
	head2 = extract_outfile(vector);
	while (head2->next)
	{
		printf("%s %d\n", head2->file_name, head2->write_mode);
		head2 = head2->next;
	}

	quote = "echo \"\'$?$GO$HOME$HOME$HOME$HOME$? $\'\"" ;
	i = 0;
	vector = ft_split_group(quote, TRUE, TRUE);
	while (vector[i])
	{
		printf("%d: %s\n", i + 1, vector[i]);
		i++;
	}
	i = 0;
	result = extract_command(vector, ft_strlen(quote));
	handle_quote(result, envp);
	while (result[i])
	{
		printf("%d: %s\n", i + 1, result[i]);
		i++;
	}
	return (0);
}
