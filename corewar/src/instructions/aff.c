/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** aff
*/

#include "my.h"

void display_aff(int id, int value)
{
    my_putstr("Player ");
    my_put_nbr(id);
    my_putstr(" display: ");
    my_putchar(value);
    my_putchar('\n');
}

int aff(cha_t *champ, instruction_t *inst)
{
    int *params = get_params(inst->vm, champ->pc + 1);
    int value = 0;

    champ->cycle = 0;
    if (params[0] != 1 || (params[4] - params[1] != 1))
        return (1);
    value = inst->vm[champ->pc + params[1]] % 256;
    if (value != 0)
        display_aff(champ->player_id, value);
    champ->pc = get_pc(params, 0, champ->pc);
    return (0);
}