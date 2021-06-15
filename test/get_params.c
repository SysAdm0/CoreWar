/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

int get_two_complement(int decimal)
{
    unsigned int conv;
    int nb = 0;
    char res[8];

    for (unsigned int i = 0; i < 8; i++) {
        conv = 1u << (8 - 1 - i);
        if (decimal & conv)
            res[i] = '1';
        else
            res[i] = '0';
    }
    res[8] = '\0';
    for (int x = 0; x < 8; x++)
        nb = nb * 10 + (res[x] - 48);
    return (nb);
}

int *rev_arg(int *arg)
{
    static int rev[4];

    for (int x = 3, y = 0; x >= 0; x--)
        rev[y++] = arg[x];
    return (rev);
}

int *get_arg(int ocp)
{
    static int arg[4];
    int mod = 0;
    int add = 0;
    char bin[8];

    while (ocp > 0) {
        mod = ocp % 10;
        ocp = ocp / 10;
        bin[add++] = mod;
    }
    while (add < 8)
        bin[add++] = 0;
    add = 0;
    for (int x = 0; x < 8; x += 2) {
        arg[add++] = bin[x + 1] * 10 + bin[x];
    }
    return (rev_arg(arg));
}


Test(get_two_complement, unit_test)
{
    int value = get_two_complement(68);

    cr_assert_eq(value, 1000100);
}

Test(get_arg, unit_test)
{
    int *value = get_arg(get_two_complement(68));

    cr_assert_eq(value[0], 01);
    cr_assert_eq(value[1], 00);
    cr_assert_eq(value[2], 01);
    cr_assert_eq(value[3], 00);
}