/*
** EPITECH PROJECT, 2021
** my_str_header.c
** File description:
** my_str_header
*/

#include "my.h"

char *my_str_header(char *src, int size)
{
    char *tmp = malloc(sizeof(char) * size);

    my_memset(tmp, 0, size);
    my_memcpy(tmp, src, my_strlen(src));
    return tmp;
}