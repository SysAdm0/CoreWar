/*
** EPITECH PROJECT, 2021
** add_label
** File description:
** add_label
*/

#include "my.h"

void add_label(char *str, int *pos, int *line)
{
    int i = 0;
    char comment = 0;
    char nl = 0;

    for (; str[i] && str[i] != COMMENT_CHAR && str[i] != ' ' &&
        str[i] != '\t' && str[i] != '\n'; i++);
    if (str[i] == COMMENT_CHAR)
        comment = 1;
    if (str[i] == ' ' || str[i] == '\t')
        nl = 1;
    str[i] = '\0';
    if (comment) {
        i++;
        for (; str[i] && str[i] != '\n'; i++);
    }
    *pos += 1;
    lex_new(str, LABEL, *line);
    if (nl)
        *line -= 1;
}