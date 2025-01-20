#include "../../includes/parsing.h"
#include "../../includes/minishell.h"


int main(int argc, char **argv, char **envp)
{
    t_minishell minishell;
    (void) argv;
    (void) argc;
    
    config_minishell_structure (&minishell, envp);
    
    int i = 0;
    
    while(minishell.env[i])
    {
        printf(" this is %d env : %s\n",i,minishell.env[i]);
        i++;
    }

    i = 0;

    while(minishell.path[i])
    {
        printf(" this is %d path : %s\n",i,minishell.path[i]);
        i++;
    }

    
    free_list(minishell.path);
    free_list(minishell.env);
    return 0;
}