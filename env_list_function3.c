
#include "interface.h"

void    free_env_node(t_env_node *node)
{
    if (node->key)
        free(node->key);
    if (node->value)
        free(node->value);
    free(node);
}

void    free_env_list(t_env_node **head)
{
    t_env_node  *tmp;
    t_env_node  *next;

    if (!(head) || !(*head))
        return ;
    tmp = *head;
    while (tmp != NULL)
    {
        next = tmp->next;
        free_env_node(tmp);
        tmp = next;
    }
    *head = NULL;
}