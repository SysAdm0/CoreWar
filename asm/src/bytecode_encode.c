/*
** EPITECH PROJECT, 2021
** bytecode_encode
** File description:
** bytecode_encode
*/

#include "my.h"

int byte_encode(char *code)
{
    int i = 0;
    char enc = 0;

    for (; code[i]; i++) {
        if (i == 0 || code[i - 1] == SEPARATOR_CHAR) {
            if (code[i] == 'r')
                enc |= 1;
            else if (code[i] == DIRECT_CHAR)
                enc |= 2;
            else
                enc |= 3;
            enc = (enc << 2);
        }
    }
    while (!(enc & 0xC0))
        enc = (enc << 2);
    byte_add(&enc, 1);
    return 1;
}

int byte_if_encode(op_t op)
{
    if ((op.type[0] != T_REG && op.type[0] != T_DIR &&
            op.type[0] != T_IND && op.type[0] != 0) ||
        (op.type[1] != T_REG && op.type[1] != T_DIR &&
            op.type[1] != T_IND && op.type[1] != 0) ||
        (op.type[2] != T_REG && op.type[2] != T_DIR &&
            op.type[2] != T_IND && op.type[2] != 0))
        return 1;
    return 0;
}