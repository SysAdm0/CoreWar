/*
** EPITECH PROJECT, 2021
** my_strchr
** File description:
** my_strchr
*/

#include <stdlib.h>

char *my_strchr(const char *str, char c)
{
    char *ptr = (char *)str;
    char sym = (char)c;

    while (*ptr && !(*ptr == sym))
        ptr++;
    return ((*ptr == sym) ? ptr : NULL);
}