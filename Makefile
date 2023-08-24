# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 11:48:36 by sangwoki          #+#    #+#              #
#    Updated: 2023/08/24 17:51:57 by cahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMPILE_FLAGS = -I${HOME}/.brew/opt/readline/include
NAME = minishell
LIBFT = ./libft/libft.a
SRCS = 	./main.c ./general_function.c ./main_utility.c \
		./env_list_function1.c \
		./env_list_function2.c \
		./env_list_function3.c \
		./parsing/parsing_error.c \
		./parsing/tokenizer.c \
		./parsing/preprocessing.c \
		./parsing/extract_feature.c \
		./parsing/parsing_error.c \
		./parsing/tokenizer.c \
		./parsing/utility.c \
		./parsing/ft_split_group.c \
		./parsing/ft_split_pipe.c \
		./parsing/handle_symbol.c \
		./parsing/execute_dollar.c \
		./parsing/token_free.c \
		./signal/signal.c \
		./signal/term_set.c \
		./execute/execute_file_check.c \
		./execute/execute.c \
		./execute/execute_utility.c \
		./execute/ft_cd.c \
		./execute/ft_cd_utility.c \
		./execute/ft_echo.c \
		./execute/ft_env.c \
		./execute/ft_exit.c \
		./execute/ft_export.c \
		./execute/ft_pwd.c \
		./execute/ft_unset.c \
		./execute/heredoc.c \
		./execute/parent_processing.c \
		./execute/token_processing.c \

OBJS = $(SRCS:.c=.o)
INCS = ./interface.h \
		./parsing/parsing.h \
		./signal/signal.h \
		./execute/execute.h

all : $(NAME)
$(NAME) : $(OBJS)
	make -C ./libft all
	$(CC) $(CFLAGS) $(LINKING_FLAGS) $^ $(LIBFT) -o $@
%.o : %.c
	$(CC) $(CFLAGS) $(COMPILE_FLAGS) -c $< -o $@
clean :
	make -C ./libft fclean
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean