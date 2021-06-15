/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my_strstr
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int count = 0;
    int ptr = 0;

    for (int i = 0; str[i] != '\0'; i++, ptr++) {
        for (; str[i] == to_find[count]; count++);
        if (count == my_strlen(&to_find[0]))
            return (&str[ptr - (my_strlen(&to_find[0]) - 1)]);
    }
    return NULL;
}