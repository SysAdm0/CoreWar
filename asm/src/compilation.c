/*
** EPITECH PROJECT, 2021
** compilation
** File description:
** compilation
*/

#include "my.h"

int rev_indian(int n)
{
    int rev = 0;

    rev += (n & 0xFF);
    rev <<= 8;
    rev += (n & 0xFF00) >> 8;
    rev <<= 8;
    rev += (n & 0xFF0000) >> 16;
    rev <<= 8;
    rev += (n & 0xFF000000) >> 24;
    return rev;
}

void compilation(char *file, lex_t *lex)
{
    int size = 0;
    lex_t *ltmp = lex;

    for (; ltmp; ltmp = ltmp->next) {
        switch (ltmp->type) {
            case CMD: write_cmd(ltmp->code);
                break;
            case LABEL: lab_new(ltmp, size);
                break;
            case OPCODE: size += byte_size(ltmp);
                break;
        }
    }
    ltmp = lex;
    for (; ltmp; ltmp = ltmp->next) {
        if (ltmp->type == OPCODE)
            byte_new(ltmp);
    }
    head_size(size);
    write_bytecode(file, size);
}