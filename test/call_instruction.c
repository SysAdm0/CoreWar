/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

int find_next_opcode(int pc, int *vm)
{
    int nb = 0;
    int d4[6] = {1, 2, 6, 7, 8, 13};
    int d2[6] = {9, 10, 11, 12, 14, 15};

    for (int x = 0; x < 6; x++) {
        if (vm[pc] == x)
            nb = 4;
    }
    if (nb == 0)
        nb = 2;
    for (; nb <= 6411; nb++) {
        for (int op = 1; op <= 16; op++) {
            if (vm[pc + nb] == op)
                return (nb);
        }
    }
    return (-1);
}

int check_return(int ret, int pc, int *inst)
{
    int next_op = -1;

    if (ret == 1)
        next_op = pc + find_next_opcode(pc, inst);
    return (next_op);
}

Test(find_next_opcode, unit_test)
{
    int tab[10] = {3,0,0,0,8,3,2,4,6,8};
    int value = find_next_opcode(0, tab);

    cr_assert_eq(value, 4);
}

Test(check_return, unit_test)
{
    int tab[10] = {3,0,0,0,8,3,2,4,6,8};
    int value = check_return(1, 0, tab);

    cr_assert_eq(value, 4);
}