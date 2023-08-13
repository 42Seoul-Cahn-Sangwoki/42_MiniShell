# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 11:48:36 by sangwoki          #+#    #+#              #
#    Updated: 2023/08/13 15:44:55 by sangwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Werror -Wall -Wextra -lreadline -L${HOME}/.brew/opt/readline/lib -I${HOME}/.brew/opt/readline/include
NAME = minishell
LIBFT = ./libft/libft.a
SRCS = 	./main.c \
		./parsing/parsing_error.c \
		./parsing/tokenizer.c \
		./parsing/parsing_free.c \
		./parsing/preprocessing.c \
		./parsing/extract_feature.c \
		./parsing/parsing_error.c \
		./parsing/tokenizer.c \
		./parsing/utility.c \
		./parsing/ft_split_group.c \
		./signal/signal.c \
		./signal/term_set.c \
		

OBJS = $(SRCS:.c=.o)
INCS = interface.h \
		./parsing/parsing.h \

all : $(NAME)
$(NAME) : $(OBJS)
	make -C ./libft all
	$(CC) $(CFLAGS) -lreadline $^ $(LIBFT) -o $@ㅇ
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	make -C ./libft fclean
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean