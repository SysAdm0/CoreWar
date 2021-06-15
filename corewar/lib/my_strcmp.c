/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** epitech > epita
*/

#include "my.h"

int my_strcmp(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
        return (0);
    for (int x = 0; str1[x] != '\0'; x++) {
        if (str1[x] != str2[x])
            return (0);
    } return (1);
}