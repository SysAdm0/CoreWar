/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** lld
*/

#include "my.h"

int lld(cha_t *champ, instruction_t *inst)
{
    int *params;
    int value = 0;

    champ->cycle = 0;
    params = get_params(inst->vm, champ->pc + 1);
    if (params[0] != 2 || (is_index(params, 1) == 1
        && p_type(params, 1) != 4) || is_register(params, 2) == 1)
        return (1);
    value = params_value(inst->vm, champ->pc + params[1], champ->pc +params[2]);
    if (value == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    inst->vm[champ->pc + params[1]] = value;
    champ->pc = get_pc(params, 0, champ->pc);
    return (0);
}