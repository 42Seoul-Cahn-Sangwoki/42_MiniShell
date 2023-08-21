
#include "../interface.h"
#include "execute.h"

void    ft_echo(char **parameter)
{
    int i;

    i = 1;
    while (parameter[i])
    {
        printf("%s ", parameter[i]);
        ++i;
    }
    printf("\n");
}
