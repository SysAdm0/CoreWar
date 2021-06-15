/*
** EPITECH PROJECT, 2021
** add_cmd
** File description:
** add_cmd
*/

#include "my.h"

void add_cmd(char *str, int *pos, int line)
{
    int i = 0;
    char comment = 0;

    while (str[i] && str[i] != COMMENT_CHAR && str[i] != '\n')
        i++;
    if (str[i] == COMMENT_CHAR)
        comment = 1;
    str[i] = '\0';
    if (comment) {
        i++;
        while (str[i] && str[i] != '\n')
            i++;
    }
    *pos += i;
    lex_new(str, CMD, line);
}