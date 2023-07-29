/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:18:02 by sangwoki          #+#    #+#             */
/*   Updated: 2023/07/29 21:09:03 by sangwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "libft/libft.h"
# include <signal.h>
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define FALSE 0
# define TRUE 1

# include"base.h"

// tokenizer.c
int		is_whitespace(char *line);
int		pipex_count(char *line);
t_node	*init_token(int pipex_counter, char *line);
int		tokenizer(int pipex_couter, char *line, t_node **node);
t_node	*command_line(char *line);

// parsing_error_handler.c
int		error_handliing(char **curpus);
void	free_corpus(char **curpus);

#endif PARSING_H