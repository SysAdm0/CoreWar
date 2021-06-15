/*
** EPITECH PROJECT, 2020
** my_atoi
** File description:
** my_atoi
*/

#include "my.h"

int my_atoi(char *str)
{
    int sign = 0;
    int res = 0;

    for (; is_space((int)*str); str++);
    if (*str == '-') {
        sign = 1;
        str++;
    } else if (*str == '+') {
        str++;
    }
    while (*str != '\0' && is_digit(*str))
        res = res * 10 + (*str++ - '0');
    if (sign)
        return (-res);
    else
        return res;
}