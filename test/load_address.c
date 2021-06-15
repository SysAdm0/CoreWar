/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

int size_occured(int *sz, int nb)
{
    int len = 0;

    for (int x = 0; x < nb; x++)
        len += sz[x];
    return (len);
}

int load_address(int *sz, int nb, int load)
{
    int op = 6411 - size_occured(sz, nb);
    int space = space = op / nb;

    if (load == 0 || load > space)
        return (space);
    else
        return (load);
}

Test(size_occured, unit_test)
{
    int sz[4] = {200,121,53,10};
    int nb = 4;
    int value = size_occured(sz, nb);

    cr_assert_eq(value, 384);
}

Test(load_address, unit_test)
{
    int sz[4] = {200,121,53,10};
    int nb = 4;
    int load = 500;
    int value = load_address(sz, nb, load);

    cr_assert_eq(value, 500);
}