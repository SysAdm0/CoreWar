/*
** EPITECH PROJECT, 2021
** syn_args
** File description:
** syn_args
*/

#include "my.h"

void check_syntax_args(lex_t *lex, op_t op, int pos)
{
    int i = 0;
    int nbr = 0;
    char *code = &lex->code[pos];
    char mask;

    for (; code[i]; i++) {
        if (i == 0 || code[i - 1] == SEPARATOR_CHAR) {
            mask = 0;
            is_valid(&code[i], &mask, 0);
            if (mask == 0)
                exit(84);
            if (!(op.type[nbr] & mask) && !(op.type[nbr] & mask) &&
                !(op.type[nbr] & mask))
                exit(84);
            nbr++;
        }
    }
}