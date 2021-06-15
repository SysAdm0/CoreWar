/*
** EPITECH PROJECT, 2021
** my_memcpy
** File description:
** my_memcpy
*/

#include <stdlib.h>

void my_memcpy(void *dst, void *src, size_t size)
{
    char *d = (char *)dst;
    char *s = (char *)src;

    for (int i = 0; i < size; i++)
        d[i] = s[i];
}