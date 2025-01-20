#include "../../includes/builtin.h"
#include "../../includes/minishell.h"

void export_var_to_env (t_minishell* minishell , char* var)
{
   int i;
   char **new_array;

   i = 0;
   while(minishell->env[i])
        i++;
    new_array = ft_calloc(sizeof(char *),(i + 2));
    if(!new_array)
        return;
    i = -1;
    while(minishell->env[++i])
        new_array[i] = minishell->env[i];
    new_array[i] = ft_strdup(var);
    if(!new_array[i])
    {
        free_list(new_array);
        return;
    }
    free_list(minishell->env);
    minishell->env = new_array;
}
