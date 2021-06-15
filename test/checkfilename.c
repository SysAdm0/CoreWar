/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

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

Test(champlen, unit_test)
{
    char str[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int value = champlen(str);

    cr_assert_eq(value, 6);
}

Test(checkendcor, unit_test)
{
    char str[8] = {'t', 'e', 's', 't', '.', 'c', 'o', 'r'};
    int value = checkendcor(str, 4);

    cr_assert_eq(value, 0);
}

Test(checkfilename, unit_test)
{
    static char *champ[3] = {"test.cor", "42.cor", "tyron.cor"};
    static char *champerr[3] = {"test.cor", "42.cor", "tyron"};
    int value = checkfilename(champ);

    cr_assert_eq(value, 0);
    value = checkfilename(champerr);
    cr_assert_eq(value, 84);
}