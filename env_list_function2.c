
#include "interface.h"

t_env_node    *copy_env_return_head(char **envp)
{
    t_env_node  *head;
	int         i;

    i = 0;
    head = NULL;
    while (envp[i])
    {
        add_back(&head, get_node(envp[i]));
        ++i;
    }
    return (head);
}

void    delete_node(t_env_node **head, t_env_node *node)
{
    if (!node)
    {
        printf("node is absence\n");
        return ;
    }
    if (node->prev != NULL)
        node->prev->next = node->next;
    else // head
        *head = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    free(node);
}

t_env_node  *search_node_by_key(t_env_node *head, const char *key)
{
    t_env_node  *search;

    search = head;
    while (search != NULL)
    {
        if (!ft_strncmp(key, search->key, ft_strlen(search->key)))
            return (search);
        search = search->next;
    }
    return (search);
}

int     return_env_list_size(t_env_node *head)
{
    t_env_node  *search;
    int         i;

    search = head;
    i = 0;
    while (search != NULL)
    {
        ++i;
        search = search->next;
    }
    return (i);
}

char    **make_origin_form_envp(t_env_node *head)
{
    char    **origin_envp;
    int     size;
    int     i;
    char    *tmp;

    size = return_env_list_size(head);
    origin_envp = (char **)malloc(sizeof(char *) * (size + 1));
    if (!origin_envp)
        print_stderr("Malloc");
    i = 0;
    while (i < size)
    {
        if (!head->value)
            origin_envp[i] = ft_strdup(head->key);
        else
        {
            tmp = ft_strjoin(head->key, "=");
            origin_envp[i] = ft_strjoin(tmp, head->value);
            free(tmp);
        }
        head = head->next;
        ++i;
    }
    origin_envp[i] = 0;
    return (origin_envp);
}
