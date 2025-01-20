#ifndef MINISHELL_H
#define MINISHELL_H


# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <dirent.h>
# include "../libft/includes/libft.h"
# include "lexer.h"
# include "parsing.h"
# include "builtin.h"
# include "general_utils.h"


typedef struct s_minishell
{
	char			empty_env;
	char			*prompt;
	char			**env;
	char			**path;
	char			*home;
	char			*user;
	char			*pwd;
	char			*oldpwd;
	char			*name;
	int				pipes;
	int				exit;
	int				nprompts;
	int				nint_mode;
	int				line_count;
	char			**lines;
	int				original_stdin;
	int				original_stdout;
	pid_t			*pids;
	int				fd[2];
	struct s_lexer	*lexer;
	struct s_parser	*parser;
}	t_minishell;

void 	config_minishell_structure(t_minishell *minishell, char** envp);
char	**get_env(char **envp);
char	 *get_var_from_env(char **env, char* var);
char 	**get_path(t_minishell *minishell,char **env);

#endif