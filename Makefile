# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 11:48:36 by sangwoki          #+#    #+#              #
#    Updated: 2023/08/14 23:14:46 by sangwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
LINKING_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
COMPILE_FLAGS = -I${HOME}/.brew/opt/readline/include
NAME = minishell
LIBFT = ./libft/libft.a
SRCS = 	./main.c ./general_function.c \
		./parsing/parsing_error.c \
		./parsing/tokenizer.c \
		./parsing/preprocessing.c \
		./parsing/extract_feature.c \
		./parsing/parsing_error.c \
		./parsing/tokenizer.c \
		./parsing/utility.c \
		./parsing/ft_split_group.c \
		./parsing/handle_symbol.c \
		./parsing/execute_dollar.c \
		./signal/signal.c \
		./signal/term_set.c \
		

OBJS = $(SRCS:.c=.o)
INCS = interface.h \
		./parsing/parsing.h \
		./signal/signal.h \

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