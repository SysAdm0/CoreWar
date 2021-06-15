/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** example of bad code:
*/
#include "my.h"

int wordlen(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return (a);
}

char *my_strdup(char const *str)
{
    int lenword = wordlen(str);
    char *strb = malloc(sizeof(char) * lenword + 1);

    for (int i = 0; str[i] != '\0'; i++) {
        strb[i] = str[i];
    }
    strb[lenword] = '\0';
    return (strb);
}
