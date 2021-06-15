/*
** EPITECH PROJECT, 2021
** check_lexer.c
** File description:
** check_lexer
*/

#include "my.h"

static void analyse(char *src, int *pos, int *line)
{
    int i = 0;

    while (src[i] && !is_space(src[i])) {
        if (src[i] == COMMENT_CHAR) {
            while (src[i] && src[i] != '\n')
                i++;
            *pos += i;
            return;
        }
        i++;
    }
    if (i > 0 && src[i - 1] == LABEL_CHAR)
        add_label(src, pos, line);
    else if (is_cmd(src, i))
        add_cmd(src, pos, *line);
    else
        add_opcode(src, pos, *line);
}

lex_t *check_lexer(char *src)
{
    int line = 1;
    int pos = 0;

    while (src[pos]) {
        if (!is_space(src[pos])) {
            analyse(&src[pos], &pos, &line);
            line++;
        } else if (src[pos] == '\n') {
            line++;
        }
        pos++;
    }
    return lex_get();
}