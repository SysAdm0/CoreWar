/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

int is_register(int *params, int nb)
{
    int size;
    int ret = 0;

    if (params[0] == 1)
        size = params[4] - params[1];
    else
        size = params[nb + 1] - params[nb];
    ret = (size == 1) ? 0 : 1;
    return (ret);
}

int is_index(int *params, int nb)
{
    int size;
    int ret = 0;

    if (params[0] == 1)
        size = params[4] - params[1];
    else
        size = params[nb + 1] - params[nb];
    ret = (size == 2) ? 0 : 1;
    return (ret);
}

int p_type(int *params, int nb)
{
    int size;

    if (params[0] == 1)
        size = params[4] - params[1];
    else
        size = params[nb + 1] - params[nb];
    if (size == 2 || size == 4)
        return (size);
    else
        return (1);
}

Test(is_register, unit_test)
{
    int params[5] = {3,2,3,5,7};
    int nb = 3;
    int value = p_type(params, nb);

    cr_assert_eq(value, 2);
}

Test(is_index, unit_test)
{
    int params[5] = {3,2,3,5,7};
    int nb = 2;
    int value = p_type(params, nb);

    cr_assert_eq(value, 2);
}

Test(p_type, unit_test)
{
    int params[5] = {3,2,3,5,7};
    int nb = 1;
    int value = p_type(params, nb);

    cr_assert_eq(value, 1);
}