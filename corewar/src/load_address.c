/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** load_address
*/

#include "my.h"

int size_occured(champ_t ch)
{
    int len = 0;

    for (int x = 0; x < ch.sz; x++)
        len += ch.size[x];
    return (len);
}

int load_address(char **champ, champ_t ch, args_s args)
{
    int op = MEM_SIZE - size_occured(ch);
    int space = space = op / ch.sz;

    if (args.load_address == 0 || args.load_address > space)
        return (space);
    else
        return (args.load_address);
}