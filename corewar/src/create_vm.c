/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** create_vm
*/

#include "my.h"

int *create_vm(char **champ, int addr, champ_t ch, args_s args)
{
    static int vm[MEM_SIZE];
    int pos = 0;
    int space = 0;
    int nb_ch = ch.sz;

    for (int x = 0; x < MEM_SIZE; x++) {
        if (x == 0) {
            for (int y = 0; y < ch.size[pos]; y++)
                vm[x++] = champ[pos][y];
            pos++;
            nb_ch--;
        } else if (space >= addr && nb_ch != 0) {
            for (int y = 0; y < ch.size[pos]; y++)
                vm[x++] = champ[pos][y];
            pos++;
            nb_ch--;
            space = 0;
        } else
            vm[x] = 0;
        space++;
    } return (vm);
}