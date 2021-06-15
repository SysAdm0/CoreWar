/*
** EPITECH PROJECT, 2021
** add_opcode.c
** File description:
** add_opcode
*/

#include "my.h"

void add_opcode(char *str, int *pos, int line)
{
    int i = 0;
    char comment = 0;

    for (; str[i] && str[i] != COMMENT_CHAR && str[i] != '\n'; i++);
    if (str[i] == COMMENT_CHAR)
        comment = 1;
    str[i] = '\0';
    if (comment) {
        i++;
        for (; str[i] && str[i] != '\n'; i++);
    }
    *pos += i;
    lex_new(str, OPCODE, line);
}