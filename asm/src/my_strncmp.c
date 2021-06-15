/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int result = 0;
    int i = 0;

    for (; (s1[i] != '\0' && s2[i] != '\0') && i != n; i++)
        if (s1[i] != s2[i]) {
            result = s1[i] - s2[i];
            break;
        }
    if (result == 0 && i < n) {
        if (my_strlen(&s1[0]) > my_strlen(&s2[0]))
            return (s1[i]);
        else if (my_strlen(&s1[0]) < my_strlen(&s2[0]))
            return (s2[i] * -1);
    }
    return (result);
}