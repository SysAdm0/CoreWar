/*
** EPITECH PROJECT, 2021
** check_syntax.c
** File description:
** check_syntax
*/

#include "my.h"

static void set_label(lex_t *lex)
{
    int i = 0;

    while (lex->code[i] && lex->code[i] != LABEL_CHAR &&
        my_strchr(LABEL_CHARS, lex->code[i]) != NULL)
        i++;
    if (lex->code[i] != LABEL_CHAR)
        exit(84);
}

static void set_cmd(lex_t *lex)
{
    int i = 0;
    int guil = 0;

    for (; lex->code[i] && !is_space(lex->code[i]); i++);
    if (!is_cmd(lex->code, i))
        exit(84);
    for (; lex->code[i] && guil < 2; i++) {
        if (lex->code[i] == '"')
            ++guil;
    }
    for (; lex->code[i] && is_space(lex->code[i]); i++);
    if (guil != 2 || lex->code[i])
        exit(84);
}

static void set_opcode(lex_t *lex, int j)
{
    int i = 0;
    char nbr = 1;
    op_t op;

    for (; lex->code[i] && !is_space(lex->code[i]); i++);
    lex->code[i] = '\0';
    op = get_by_mnemo(lex->code);
    lex->code[i] = ' ';
    if (op.code == 0)
        exit(84);
    j = i;
    for (; lex->code[i]; i++) {
        if (lex->code[i] == SEPARATOR_CHAR)
            nbr++;
    }
    if (op.nbr_args != nbr)
        exit(84);
    for (; lex->code[j] && is_space(lex->code[j]); j++);
    check_syntax_args(lex, op, j);
}

void check_syntax(lex_t *lex)
{
    for (; lex; lex = lex->next) {
        switch (lex->type) {
            case LABEL: set_label(lex);
                break;
            case CMD: set_cmd(lex);
                break;
            case OPCODE: set_opcode(lex, 0);
                break;
        }
    }
}