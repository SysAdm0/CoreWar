/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** call_instructions
*/

#include "my.h"

int check_return(int ret, int pc, instruction_t *inst)
{
    int next_op = -1;

    if (ret == 1)
        next_op = pc + find_next_opcode(pc, inst);
    return (next_op);
}

int call_instructions_p2(cha_t *champ, instruction_t *inst)
{
    if (inst->vm[champ->pc] == 9 && champ->cycle == 20)
        return (check_return(zjmp(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 10 && champ->cycle == 25)
        return (check_return(ldi(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 11 && champ->cycle == 25)
        return (check_return(sti(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 12 && champ->cycle == 800)
        return (check_return(func_fork(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 13 && champ->cycle == 10)
        return (check_return(lld(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 14 && champ->cycle == 50)
        return (check_return(lldi(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 15 && champ->cycle == 1000)
        return (check_return(lfork(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 16)
        return (check_return(aff(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 8 && champ->cycle == 6)
        return (check_return(xor(champ, inst), champ->pc, inst));
}

int call_instructions_p1(cha_t *champ, instruction_t *inst)
{
    int status = -1;

    if (inst->vm[champ->pc] == 1 && champ->cycle == 10)
        return (check_return(live(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 2 && champ->cycle == 5)
        return (check_return(ld(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 3 && champ->cycle == 5)
        return (check_return(st(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 4 && champ->cycle == 10)
        return (check_return(add(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 5 && champ->cycle == 10)
        return (check_return(sub(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 6 && champ->cycle == 6)
        return (check_return(and(champ, inst), champ->pc, inst));
    if (inst->vm[champ->pc] == 7 && champ->cycle == 6)
        return (check_return(or(champ, inst), champ->pc, inst));
    status = call_instructions_p2(champ, inst);
    if (status != -1)
        champ->pc = status;
}

void call_instructions(cha_t *champ, instruction_t *inst)
{
    if ((inst->vm[champ->pc] == 6 || inst->vm[champ->pc] == 7
    || inst->vm[champ->pc] == 8) && champ->cycle == 6)
        call_instructions_p1(champ, inst);
    if ((inst->vm[champ->pc] == 4 || inst->vm[champ->pc] == 5
    || inst->vm[champ->pc] == 1 || inst->vm[champ->pc] == 13)
    && champ->cycle == 10)
        call_instructions_p1(champ, inst);
    if ((inst->vm[champ->pc] == 2 || inst->vm[champ->pc] == 3)
    && champ->cycle == 5)
        call_instructions_p1(champ, inst);
    if (inst->vm[champ->pc] == 9 && champ->cycle == 20)
        call_instructions_p1(champ, inst);
    if ((inst->vm[champ->pc] == 11 || inst->vm[champ->pc] == 10)
    && champ->cycle == 25)
        call_instructions_p1(champ, inst);
    if (inst->vm[champ->pc] == 14 && champ->cycle == 50)
        call_instructions_p1(champ, inst);
    if (inst->vm[champ->pc] == 12 && champ->cycle == 800)
        call_instructions_p1(champ, inst);
    if (inst->vm[champ->pc] == 15 && champ->cycle == 1000)
        call_instructions_p1(champ, inst);
}