/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** xor
*/

#include "my.h"

int xor_params(int *params)
{
    if (is_register(params, 1) == 1 && is_index(params, 1) == 1
        && p_type(params, 1) != 4)
        return (1);
    if (is_register(params, 2) == 1 && is_index(params, 2) == 1
        && p_type(params, 2) != 4)
        return (1);
    if (is_register(params, 3) == 1)
        return (1);
    return (0);
}

int xor(cha_t *champ, instruction_t *inst)
{
    int *params = get_params(inst->vm, champ->pc + 1);
    int xor = 0;

    champ->cycle = 0;
    if (params[0] != 3 || xor_params(params) == 1)
        return (1);
    xor = params_value(inst->vm, champ->pc + params[1], champ->pc + params[2])
    ^ params_value(inst->vm, champ->pc + params[2], champ->pc + params[3]);
    if (xor == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    inst->vm[champ->pc + params[3]] = xor;
    champ->pc = get_pc(params, 0, champ->pc);
    return (0);
}