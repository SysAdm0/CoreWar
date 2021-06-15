/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_params
*/

#include "my.h"

int get_two_complement(int decimal)
{
    unsigned int conv;
    int nb = 0;
    char res[8];

    for (unsigned int i = 0; i < 8; i++) {
        conv = 1u << (8 - 1 - i);
        if (decimal & conv)
            res[i] = '1';
        else
            res[i] = '0';
    }
    res[8] = '\0';
    for (int x = 0; x < 8; x++)
        nb = nb * 10 + (res[x] - 48);
    return (nb);
}

int *rev_arg(int *arg)
{
    static int rev[4];

    for (int x = 3, y = 0; x >= 0; x--)
        rev[y++] = arg[x];
    return (rev);
}

int *get_arg(int ocp)
{
    static int arg[4];
    int mod = 0;
    int add = 0;
    char bin[8];

    while (ocp > 0) {
        mod = ocp % 10;
        ocp = ocp / 10;
        bin[add++] = mod;
    }
    while (add < 8)
        bin[add++] = 0;
    add = 0;
    for (int x = 0; x < 8; x += 2) {
        arg[add++] = bin[x + 1] * 10 + bin[x];
    }
    return (rev_arg(arg));
}

int four_or_two(int op)
{
    int d4[6] = {1, 2, 6, 7, 8, 13};
    int d2[6] = {9, 10, 11, 12, 14, 15};

    for (int x = 0; x < 6; x++) {
        if (d4[x] == op)
            return (T_IND);
    }
    for (int x = 0; x < 6; x++) {
        if (d2[x] == op)
            return (T_DIR);
    }
    return (-1);
}

int *get_params(int *vm, int ocp)
{
    static int params[5];
    int size = 0;
    int *arg;

    arg = get_arg(get_two_complement(vm[ocp]));
    for (int x = 1; x < 4 && arg[x - 1] != 0; x++, size++) {
        if (arg[x - 1] == 1)
            params[x] = T_REG;
        else if (arg[x - 1] == 10)
            params[x] = four_or_two(vm[ocp - 1]);
        else
            params[x] = IND_SIZE;
    }
    params[4] = 2;
    for (int x = 1; x <= size; x++)
        params[4] += params[x];
    params[3] = params[1] + params[2] + 2;
    params[2] = params[1] + 2;
    params[1] = 2;
    params[0] = size;
    return (params);
}