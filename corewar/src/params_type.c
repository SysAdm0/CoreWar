/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** params_type
*/

#include "my.h"

int is_register(int *params, int nb)
{
    int size;
    int ret = 0;

    if (params[0] == 1)
        size = params[4] - params[1];
    else
        size = params[nb + 1] - params[nb];
    ret = (size == 1) ? 0 : 1;
    return (ret);
}

int is_index(int *params, int nb)
{
    int size;
    int ret = 0;

    if (params[0] == 1)
        size = params[4] - params[1];
    else
        size = params[nb + 1] - params[nb];
    ret = (size == 2) ? 0 : 1;
    return (ret);
}

int p_type(int *params, int nb)
{
    int size;

    if (params[0] == 1)
        size = params[4] - params[1];
    else
        size = params[nb + 1] - params[nb];
    if (size == 2 || size == 4)
        return (size);
    else
        return (1);
}