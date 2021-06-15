/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** lldi
*/

#include "my.h"

int lldi_params(int *params)
{
    if (is_register(params, 1) == 1 && is_index(params, 1) == 1
        && p_type(params, 1) != 2)
        return (1);
    if (is_index(params, 2) == 1 && p_type(params, 2) != 2)
        return (1);
    if (is_register(params, 3) == 1)
        return (1);
    return (0);
}

int lldi(cha_t *champ, instruction_t *inst)
{
    int *prs;
    int value = 0;

    champ->cycle = 0;
    prs = get_params(inst->vm, champ->pc + 1);
    if (prs[0] != 3 || lldi_params(prs) == 1)
        return 1;
    value = params_value(inst->vm, champ->pc + prs[1], champ->pc + prs[2])
            + params_value(inst->vm, champ->pc + prs[2], champ->pc + prs[3]);
    if (value == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    inst->vm[champ->pc + prs[3]] = inst->vm[champ->pc + value];
    champ->pc = get_pc(prs, 0, champ->pc);
    return (0);
}