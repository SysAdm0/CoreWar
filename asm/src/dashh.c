/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** dashh
*/
#include "my.h"

int cmph(char *dash)
{
    char str[] = "-h";

    for (int i = 0; dash[i] != '\0'; i++) {
        if (dash[i] != str[i])
            return (1);
    } return (0);
}

int checkh(char *dash)
{
    if (cmph(dash) == 0)
        return (0);
    return (1);
}

void dashh(void)
{
    my_putstr("USAGE\n");
    my_putstr("        ./asm file_name[.s]\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("file_name file in assembly language to be converted into");
    my_putstr(" file_name.cor, an executable in the Virtual Machine\n");
}