/*
** EPITECH PROJECT, 2021
** main
** File description:
** asm
*/

#include "my.h"

int main(int argc, char **argv)
{
    if (argc == 1 || (argc == 2 && checkh(argv[1]) == 0)) {
        dashh();
        return 0;
    } else if (argc == 2 && (my_asm(argv[1]) == 84)) {
        return 84;
    }
    return 0;
}