/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** print_vm
*/

#include "my.h"

void print_vm(int *vm)
{
    for (int x = 0; x < MEM_SIZE; x++) {
        if (x % 64 == 0)
            my_putchar('\n');
        my_put_nbr(vm[x]);
        my_putchar(' ');
    }
}