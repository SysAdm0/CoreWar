/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** params_value
*/

#include "my.h"

int params_value(int *vm, int start, int end)
{
    int result = 1;
    int pass = 0;

    for (int x = start; x < end; x++) {
        if (vm[x] != 0 && x == start) {
            pass = 1;
            result = vm[x];
        } else if (vm[x] != 0) {
            pass = 1;
            result = result * vm[x];
        }
    }
    if (result < 0)
        result = result * -1;
    if (pass == 0)
        return (0);
    else
        return (result);
}