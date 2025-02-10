#include "../../includes/minishell.h"


void config_minishell_structure(t_minishell *minishell, char** envp)
{
    ft_memset(minishell,0,sizeof(t_minishell));
    minishell->env = get_env(envp);
    minishell->path = get_path(minishell,minishell->env);
    minishell->pwd = get_pwd(minishell, minishell->env);
    minishell->oldpwd = get_var_from_env(minishell->env,"OLDPWD");
    if (!minishell->oldpwd)
    {
        minishell->oldpwd = ft_strdup("");
        export_var_to_env(minishell,"OLDPWD");
    }
    minishell->user = get_var_from_env(minishell->env, "USER");
    if (!minishell->user)
        minishell->user = get_user_manually(minishell);
    minishell->name = get_name(minishell);
    minishell->home = get_var_from_env(minishell->env, "HOME");
    if(!minishell->home)
        minishell->home = ft_strjoin("/home/",minishell->user);
    
    add_shlvl(minishell);

}
