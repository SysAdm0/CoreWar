/*
** EPITECH PROJECT, 2020
** sti
** File description:
** example of bad code:
*/

#include "my.h"

int sti_params(int *params)
{
    if (is_register(params, 1) == 1)
        return (1);
    if (is_register(params, 2) == 1 && is_index(params, 2) == 1
        && p_type(params, 2) != 2)
        return (1);
    if (is_index(params, 3) == 1 && p_type(params, 3) != 2)
        return (1);
    return (0);
}

int sti(cha_t *champ, instruction_t *inst)
{
    int *params;
    int a = 0;

    champ->cycle = 0;
    params = get_params(inst->vm, champ->pc + 1);
    if (params[0] != 3 || sti_params(params) == 1)
        return (1);
    a = params_value(inst->vm, champ->pc + params[2], champ->pc + params[3])
    + params_value(inst->vm, champ->pc + params[3], champ->pc + params[4]);
    inst->vm[champ->pc + (a % IDX_MOD)]
    = params_value(inst->vm, champ->pc + params[1], champ->pc + params[2]);
    champ->pc = get_pc(params, 0, champ->pc);
    return (0);
}