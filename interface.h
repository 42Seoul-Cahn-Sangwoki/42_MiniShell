
#ifndef INTERFACE_H
# define INTERFACE_H

# include "libft/libft.h"
# include <signal.h>
# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

#define WRITE_NEW 0
#define WRITE_BACK 1
#define READ -1
#define HERE_DOC -2
#define SUCCESS 1
#define FAIL 0

typedef struct s_file_info
{
    char                *file_name; // Null 이면 fd값 확인
    int                 fd;
    int                 write_mode; // 여기 매크로값 넣어주셈 (> 이거는 0, >> 이거는 1, inputfile이면 -1)
    struct s_file_info  *next;
}   t_file_info;

typedef struct s_node
{
    char            **commands; // 딱 명령어 만큼만 할당해주셈
    t_file_info     *infile_head; // head 더미노드로 할지 말지 알려주셈
    t_file_info     *outfile_head;
}   t_node;

typedef struct s_env_node
{
    char                *key;
    char                *value;
    struct s_env_node   *next;
    struct s_env_node   *prev;
}   t_env_node;

typedef struct s_global
{
    t_env_node  *envp_head; // 처음에 copy_env_return_head로 초기화 해주면됨.
    int         exit;
}   t_global;
// env리스트에 필요한 함수들 웬만한거 다 구현해놨고 테스트했음.

t_global g_global_var;

void        execute(t_node *cmds, int length); // 배열과 배열 크기(크기 꼭 리턴)
void	    print_stderr(char *error_print);
void    	print_stderr_no_exit(char *command, int code);
void	    free_split(char ***split);
t_env_node  *copy_env_return_head(char **envp);
t_env_node  *get_node(const char *string);
t_env_node  *search_node_by_key(t_env_node *head, const char *key);
void        add_back(t_env_node **head, t_env_node *new);
void        modify_env_value(t_env_node *node, const char *str);
void        print_env_string_with_newline(t_env_node *node);
void        print_all_env(t_env_node *head);
void        delete_node(t_env_node **head, t_env_node *node);
int         return_env_list_size(t_env_node *head);
char        **make_origin_form_envp(t_env_node *head); // 연결리스트를 통해 원래 char **형태의 envp 만들기. 수정해도 원래 연결리스트에는 영향을 주지 않음.
void        free_env_node(t_env_node *node);
void        free_env_list(t_env_node **head);





#endif