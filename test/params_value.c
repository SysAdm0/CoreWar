/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

int params_value(int *vm, int start, int end)
{
    int result = 1;
    int pass = 0;

    for (int x = start; x < end; x++) {
        if (vm[x] != 0 && x == start) {
            pass = 1;
            result = vm[x];
        } else if (vm[x] != 0) {
            pass = 1;
            result = result * vm[x];
        }
    }
    if (result < 0)
        result = result * -1;
    if (pass == 0)
        return (0);
    else
        return (result);
}

Test(params_value, unit_test)
{
    int vm[6] = {0,1,1,8,1,0};
    int value = params_value(vm, 0, 2);

    cr_assert_eq(value, 1);
    value = params_value(vm, 2, 4);
    cr_assert_eq(value, 8);
    value = params_value(vm, 4, 6);
    cr_assert_eq(value, 1);
}