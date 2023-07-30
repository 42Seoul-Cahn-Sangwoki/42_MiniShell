# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangwoki <sangwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 13:46:38 by sangwoki          #+#    #+#              #
#    Updated: 2022/11/14 14:11:47 by sangwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_M = ft_isalpha.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
SRCS_B = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		 ft_lstclear.c ft_lstiter.c ft_lstmap.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS_M = ${SRCS_M:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}
INCS = libft.h
LIBC = ar rc
NAME = libft.a
ifdef BONUS
	OBJS = $(OBJS_B) $(OBJS_M)
else
	OBJS = $(OBJS_M)
endif
all : $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS)
$(NAME) : $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS_B) $(OBJS_M)
fclean: clean
	$(RM) $(NAME)
re: fclean all
bonus:
	make BONUS=1 all
.PHONY : clean fclean re all bonus