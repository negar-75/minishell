#include "../../includes/minishell.h"


void config_minishell_structure(t_minishell *minishell, char** envp)
{
    ft_memset(minishell,0,sizeof(t_minishell));
    minishell->env = get_env(envp);
    minishell->path = get_path(minishell,minishell->env);
}