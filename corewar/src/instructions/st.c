/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** st
*/

#include "my.h"

int st(cha_t *champ, instruction_t *inst)
{
    int *params;

    champ->cycle = 0;
    params = get_params(inst->vm, champ->pc + 1);
    if (params[0] != 2 || (is_index(params, 2) == 1
    && p_type(params, 2) != 4) || is_register(params, 1) == 1)
        return (1);
    if (params[2] - params[1] == 1)
        inst->vm[champ->pc + params[1]] = champ->pc + params[2];
    else
        inst->vm[champ->pc + params[1] % IDX_MOD] = champ->pc + params[2];
    champ->pc = get_pc(params, 0, champ->pc);
    return (0);
}