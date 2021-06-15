/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** find_next_opcode
*/

#include "my.h"

int find_next_opcode(int pc, instruction_t *inst)
{
    int nb = 0;
    int d4[6] = {1, 2, 6, 7, 8, 13};
    int d2[6] = {9, 10, 11, 12, 14, 15};

    for (int x = 0; x < 6; x++) {
        if (inst->vm[pc] == x)
            nb = 4;
    }
    if (nb == 0)
        nb = 2;
    for (; nb <= MEM_SIZE; nb++) {
        for (int op = 1; op <= 16; op++) {
            if (inst->vm[pc + nb] == op)
                return (nb);
        }
    }
    return (-1);
}