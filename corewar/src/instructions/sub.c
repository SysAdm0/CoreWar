/*
** EPITECH PROJECT, 2020
** sub.c
** File description:
** example of bad code:
*/

#include "my.h"

int sub(cha_t *champ, instruction_t *inst)
{
    int *params;
    int res = 0;

    champ->cycle = 0;
    params = get_params(inst->vm, champ->pc + 1);
    if (params[0] != 3)
        return 1;
    for (int x = 1; x <= 3; x++) {
        if (is_index(params, x) == 1)
            return 1;
    }
    res = params_value(inst->vm, champ->pc
    + params[2], champ->pc + params[3]) - params_value(inst->vm, champ->pc
    + params[1], champ->pc + params[2]);
    if (res == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    inst->vm[champ->pc + params[3]] = res;
    champ->pc = get_pc(params, 0, champ->pc);
    return 0;
}