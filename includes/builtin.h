#ifndef BUILTIN_H
#define BUILTIN_H

typedef struct s_minishell t_minishell;

void export_var_to_env(t_minishell *minishell, char *var);

#endif
