#include "../../includes/general_utils.h"
#include "../../includes/minishell.h"

void free_list (char **list)
{
    int i;

    i = 0;

    while(list[i])
    {
        free(list[i]);
        i++;
    }
    free(list);
}
