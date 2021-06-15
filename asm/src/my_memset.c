/*
** EPITECH PROJECT, 2021
** my_memset
** File description:
** my_memset
*/

#include <stdlib.h>

void my_memset(void *ptr, int value, size_t size)
{
    char *p = (char *)ptr;

    for (int i = 0; i < size; i++)
        p[i] = value;
}