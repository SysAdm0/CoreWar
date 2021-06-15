/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}