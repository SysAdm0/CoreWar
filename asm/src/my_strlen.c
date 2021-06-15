/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** my_strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int len = 0;

    if (str == NULL)
        return (0);
    for (; str[len] != '\0'; len++);
    return (len);
}