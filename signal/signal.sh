gcc -Werror -Wall -Wextra -lreadline -L${HOME}/.brew/opt/readline/lib -I${HOME}/.brew/opt/readline/include ../libft/ft_putchar_fd.c \
    ../libft/ft_putstr_fd.c signal.c term_set.c test.c