/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

int get_pc(int *tab, int no_occ, int pc)
{
    if (tab == NULL && no_occ == 0) {
        printf("ERREUR: %d", pc);
        return (pc);
    }
    if (no_occ == 0)
        pc = pc + tab[4];
    else
        pc = no_occ;
    return (pc);
}

Test(get_pc, unit_test)
{
    int tab[5] = {3,2,4,6,8};
    int value = get_pc(tab, 0, 0);

    cr_assert_eq(value, 8);
}
