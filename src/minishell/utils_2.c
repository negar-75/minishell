#include "../../includes/minishell.h"

int is_it_var(char *env,char *var)
{
    int i;

    i = 0;
    while(env[i] != '=' && env[i] && var[i])
    {
        if(env[i] == var[i])
            i++;
        else
            return(0);
    }
    if (var[i] == '\0' && env[i] == '=')
		return (1);
    return (0);
}

char *get_var_from_env(char **env, char* var)
{
    int index;
    char* path_var;

    index = 0;
    if(!env || !var)
        return (NULL);
    while(env[index])
    {
        if(is_it_var(env[index],var))
            break;
        index++;
    }
    if(env[index])
        path_var = ft_substr(env[index],ft_strlen(var)+1,ft_strlen(env[index]));
    else 
        path_var = NULL;
    return (path_var);
}