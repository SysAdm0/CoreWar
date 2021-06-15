/*
** EPITECH PROJECT, 2021
** cmd
** File description:
** cmd
*/

#include "my.h"

void write_cmd(char *str)
{
    int i = 0;

    for (; !is_space(str[i]); i++);
    if (my_strncmp(str, NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)) == 0)
        head_cmd(NAME, str);
    else if (my_strncmp(str, COMMENT_CMD_STRING,
        my_strlen(COMMENT_CMD_STRING)) == 0)
        head_cmd(COMMENT, str);
}