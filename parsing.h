/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:18:02 by sangwoki          #+#    #+#             */
/*   Updated: 2023/07/30 15:38:09 by cahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include <termios.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1

# include "base.h"

// tokenizer.c
int		pipex_count(char *line);
t_node	*init_token(int pipex_counter);
int		tokenizer(int pipex_couter, char *line, t_node **node);
t_node	*command_line(char *line);
int		is_whitespace(char *line);

// parsing_error_handler.c
int		error_handling(char **curpus);
void	free_corpus(char **curpus);
void	free_token(t_node **node);

#endif