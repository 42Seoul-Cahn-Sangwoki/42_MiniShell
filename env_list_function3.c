
#include "interface.h"

void    free_env_node(t_env_node *node)
{
    if (node->key)
        free(node->key);
    if (node->value)
        free(node->value);
    free(node);
}