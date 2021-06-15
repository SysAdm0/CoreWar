/*
** EPITECH PROJECT, 2021
** lexer
** File description:
** lexer
*/

#include "my.h"

static lex_t *get(void)
{
    static lex_t lex = {CMD, NULL, 0, NULL};

    return &lex;
}

lex_t *lex_get(void)
{
    lex_t *lex = get();

    return lex->next;
}

void lex_new(char *code, enum type_e type, int line)
{
    lex_t *lex = get();
    lex_t *new = malloc(sizeof(lex_t));

    new->line = line;
    new->type = type;
    new->code = code;
    new->next = NULL;
    while (lex->next)
        lex = lex->next;
    lex->next = new;
}

void lex_free(void)
{
    lex_t *lex = lex_get();
    lex_t *tmp;

    while (lex) {
        tmp = lex;
        lex = lex->next;
        tmp->code = NULL;
        tmp->next = NULL;
        free(tmp);
    }
}