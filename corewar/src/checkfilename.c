/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** checkfilename
*/

#include "my.h"

int champlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int checkendcor(char *str, int j)
{
    char *cor = ".cor";

    for (int i = 0; str[j] != '\0'; j++, i++) {
        if (str[j] != cor[i])
            return (84);
    } return (0);
}

int checkfilename(char **champ)
{
    int point = 0;

    for (int i = 0; champ[i] != NULL; i++) {
        for (point = 0; champ[i][point] != '.'; point++);
        if (champlen(champ[i]) == point)
            return (84);
        if (checkendcor(champ[i], point) == 84)
            return (84);
    } return (0);
}