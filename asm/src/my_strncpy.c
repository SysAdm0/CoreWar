/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** my_strncpy
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int last = 0;

    for (int i = 0; i < n; i++, last++)
        dest[i] = src[i];
    if (n > my_strlen(&src[0]))
        dest[last] = '\0';
    return (dest);
}