# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cahn <cahn@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/30 11:48:36 by sangwoki          #+#    #+#              #
#    Updated: 2023/08/02 20:49:18 by cahn             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
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
		./execute/execute.c \
		./execute/execute_utility.c

OBJS = $(SRCS:.c=.o)
INCS = interface.h \
		./parsing/parsing.h \
		./execute/execute.h

all : $(NAME)
$(NAME) : $(OBJS)
	make -C ./libft all
	$(CC) $(CFLAGS) -lreadline $^ $(LIBFT) -o $@
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean :
	make -C ./libft fclean
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY: all re fclean clean