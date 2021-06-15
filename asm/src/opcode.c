/*
** EPITECH PROJECT, 2021
** opcode
** File description:
** opcode
*/

#include "my.h"

op_t get_by_mnemo(char *name)
{
    int i = 0;

    for (; op_tab[i].code != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, name) == 0)
            return op_tab[i];
    }
    return op_tab[16];
}

op_t get_by_code(char code)
{
    int i = 0;

    for (; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == code)
            return op_tab[i];
    }
    return op_tab[16];
}