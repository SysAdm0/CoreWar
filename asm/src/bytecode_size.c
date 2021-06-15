/*
** EPITECH PROJECT, 2021
** bytecode_size
** File description:
** bytecode_size
*/

#include "my.h"

static int set_size(char *code, op_t op)
{
    int i = 0;
    int size = 0;

    for (; code[i]; i++) {
        if (i == 0 || code[i - 1] == SEPARATOR_CHAR) {
            if (code[i] == 'r')
                size += 1;
            else if (code[i] == DIRECT_CHAR)
                size += op.size;
            else
                size += 2;
        }
    }
    return size;
}

int byte_size(lex_t *lex)
{
    op_t op;
    int i = 0;
    int size = 1;

    for (; !is_space(lex->code[i]); i++);
    lex->code[i] = '\0';
    op = get_by_mnemo(lex->code);
    lex->code[i] = ' ';
    for (; is_space(lex->code[i]); i++);
    if (byte_if_encode(op))
        size += 1;
    size += set_size(get_arg(lex->code), op);
    return size;
}