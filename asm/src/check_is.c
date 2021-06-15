/*
** EPITECH PROJECT, 2021
** check_is
** File description:
** check_is
*/

#include "my.h"

int is_space(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

int is_cmd(char *str, int size)
{
    if (my_strncmp(str, NAME_CMD_STRING, size) == 0 ||
        my_strncmp(str, COMMENT_CMD_STRING, size) == 0)
        return 1;
    return 0;
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

void is_valid(char *arg, char *mask, int i)
{
    if (arg[0] == 'r') {
        if (my_atoi(&arg[1]) <= REG_NUMBER && my_atoi(&arg[1]) > 0)
            *mask = T_REG;
    } else {
        *mask = T_IND;
        if (arg[0] == DIRECT_CHAR) {
            *mask = T_DIR;
            arg++;
        }
        if (arg[0] == LABEL_CHAR) {
            return;
        } else {
            i = (arg[0] == '-') ? 1 : 0;
            for (; arg[i] && arg[i] != SEPARATOR_CHAR && is_digit(arg[i]); i++);
            if (arg[i] != '\0' && arg[i] != SEPARATOR_CHAR &&
                !is_space(arg[i]))
                *mask = 0;
        }
    }
}