#include "../../includes/minishell.h"

char **get_env(char **envp)
{
    char **env;
    int count;
    int index;

    count = 0;
    if(!envp)
        return (NULL);
    while(envp[count])
        count++;
    env = ft_calloc(sizeof(char *),count + 1);
    if(env == NULL)
        return (NULL);
    index = 0;
    while(envp[index])
    {
        env[index]= ft_strdup(envp[index]);
        if(env[index] == NULL)
            return(NULL);
        index++;
    }
    return (env);
}

char **get_path(t_minishell *minishell,char **env)
{
    char    *path_from_env;
    char    **path_list;

    path_from_env = get_var_from_env(env,"PATH");
    if (!path_from_env)
    {
        path_from_env = ft_strdup("/bin:/usr/bin");
        export_var_to_env(minishell,"_=/usr/bin/env");
        minishell->empty_env = 1;
    }
    path_list = ft_split(path_from_env, ":");
    free(path_from_env);
    if (!path_list)
        return(NULL);
    return (path_list);
}