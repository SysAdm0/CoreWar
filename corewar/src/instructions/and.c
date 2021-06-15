/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** and
*/

#include "my.h"

int and_params(int *params)
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

int and(cha_t *champ, instruction_t *inst)
{
    int *params = get_params(inst->vm, champ->pc + 1);
    int and = 0;

    champ->cycle = 0;
    if (params[0] != 3 || and_params(params) == 1)
        return (1);
    and = params_value(inst->vm, champ->pc + params[1], champ->pc + params[2])
    & params_value(inst->vm, champ->pc + params[2], champ->pc + params[3]);
    if (and == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    inst->vm[champ->pc + params[3]] = and;
    champ->pc = get_pc(params, 0, champ->pc);
    return (0);
}