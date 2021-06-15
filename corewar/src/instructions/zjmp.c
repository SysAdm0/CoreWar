/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** zjmp
*/

#include "my.h"

int zjmp(cha_t *champ, instruction_t *inst)
{
    int jump = 0;
    int value = 0;

    champ->cycle = 0;
    value = params_value(inst->vm, champ->pc + 1, champ->pc + 3);
    if (champ->carry == 1) {
        jump = 1 + inst->vm[champ->pc] + value;
        champ->pc = get_pc(NULL, champ->init_pc + jump, champ->pc);
    } else {
        jump = find_next_opcode(champ->pc, inst);
        champ->pc = get_pc(NULL, champ->pc + jump, champ->pc);
    } return (0);
}