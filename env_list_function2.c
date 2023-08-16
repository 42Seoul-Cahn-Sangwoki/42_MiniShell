
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
