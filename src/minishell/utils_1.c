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

char    *get_pwd(t_minishell *minishell, char **env)
{
    char	buffer[1024];
	char	*pwd;
	char	*tmp;

	pwd = get_var_from_env(env, "PWD");
	if (!pwd)
	{
		pwd = ft_strdup(getcwd(buffer, sizeof(buffer)));
		tmp = ft_strjoin("PWD=", pwd);
		export_var_to_env(minishell, tmp);
		free(tmp);
	}
	return (pwd);
}

char* get_user_manually(t_minishell *minishell)
{   
    char    *user;
    struct  passwd *pw;
    char    *var;
    pw = getpwuid(getuid());
    if (pw)
    {
        user = pw->pw_name;
        var = ft_strjoin("USER=", pw->pw_name);
        export_var_to_env(minishell,var);
        free(var);
        return (user);
    }
    else
        return (NULL);
}

char *get_name(t_minishell *minishell)
{
    char *name;
    char *var;
    int i;

    name = get_var_from_env(minishell->env, "NAME");
    if(!name)
    {
        var = get_var_from_env(minishell->env, "SESSION_MANAGER");
        if(!var)
            return (ft_strdup(""));
        i = find_first_char(var, 0, '/');
        if(i == -1)
            return (ft_strdup(""));
        name = ft_substr(var,i+1,find_first_char(var, i,':') - i -1);
        free (var);
    }
    return (name);
}
