/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(const char *s1, const char *s2)
{
    int result = 0;
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            break;
        }
    if (result == 0) {
        if (my_strlen(&s1[0]) > my_strlen(&s2[0]))
            result = s1[i];
        else if (my_strlen(&s1[0]) < my_strlen(&s2[0]))
            result = s2[i] * -1;
    }
    return (result);
}