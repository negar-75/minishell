#ifndef PARSING_H
#define PARSING_H

typedef struct s_parser
{
    char **args;
    char *stdin_file_name;
    char *stdout_file_name;
    char *delimiter;
    int stdin_flag;
    int stdout_flag;
    int fd_err;
    struct s_parser *pre;
    struct s_parser *next;
    int nb_redirection;
    int nb_heredoc;
}t_parser;



#endif