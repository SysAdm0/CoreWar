/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc
*/

#include "my.h"

int get_pc(int *tab, int no_occ, int pc)
{
    if (tab == NULL && no_occ == 0)
        return (pc);
    if (no_occ == 0)
        pc = pc + tab[4];
    else
        pc = no_occ;
    return (pc);
}