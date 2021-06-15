/*
** EPITECH PROJECT, 2020
** convert_vm
** File description:
** example of bad code:
*/

#include "my.h"

void convert_vm_to_hexa(instruction_t inst)
{
    char *str;

    for (int x = 0; x < MEM_SIZE; x++) {
        if (x % 64 == 0)
            my_putchar('\n');
        str = convert_hexa_to_bin(inst.vm[x]);
        my_putstr(str);
        my_putchar(' ');
    }
}