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

int find_first_char(char *str, int start, char c)
 {
    int var_position;

    var_position = start;
    while(str[var_position])
    {
        if (str[var_position] == c)
            return (var_position);
        var_position++;
    }
    return (-1);
 }

void    add_shlvl(t_minishell *minishell)
{
    int i;
    int shlvl;
    char *new_shlvl;
    char *str_shlvl;

    i = 0;
    while(minishell->env[i] != NULL)  
    {
        if(ft_strncmp("SHLVL",minishell->env[i],5) == 0)
        {
            shlvl = ft_atoi(minishell->env[i] + 6) + 1;
            str_shlvl = ft_itoa(shlvl);
            new_shlvl = ft_strjoin("SHLVL=",str_shlvl);
            if(!new_shlvl)
                return;
            free(minishell->env[i]);
            minishell->env[i] = new_shlvl;
            free(str_shlvl);
        }
        i++;
    }
    export_var_to_env(minishell, "SHLVL=1");
}

void free_minishell(t_minishell *minishell)
{
    if (!minishell)
		return ;
	if (minishell && minishell->env)
		free_list(minishell->env);
	if (minishell && minishell->path)
		free_list(minishell->path);
	if (minishell && minishell->pwd)
		free(minishell->pwd);
	if (minishell && minishell->oldpwd)
		free(minishell->oldpwd);
	if (minishell && minishell->home)
		free(minishell->home);
	if (minishell && minishell->user)
		free(minishell->user);
	if (minishell && minishell->name)
		free(minishell->name);
    if (minishell->pids)
		free(minishell->pids);
	if (minishell->nint_mode)
		free_list(minishell->lines);
}
