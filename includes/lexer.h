#ifndef LEXER_H
#define LEXER_H


typedef struct s_lexer
{
    char    *word;
    char    token;
    int    index;
    struct s_lexer *prev;
    struct s_lexer *next;
}t_lexer;


#endif