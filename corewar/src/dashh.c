/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** dashh
*/
#include "my.h"

int cmph(char *dash)
{
    char *str = "-h";

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
    my_putstr("        ./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_putstr("[-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory after the ");
    my_putstr("nbr_cycle execution (if the round isn’t\n");
    my_putstr("already over) with the following format: 32 bytes/line\n");
    my_putstr("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program’s number. ");
    my_putstr("By default, the first free number\n");
    my_putstr("in the parameter order\n");
    my_putstr("-a load_address sets the next program’s loading address. ");
    my_putstr("When no address is\n");
    my_putstr("specified, optimize the addresses so that the ");
    my_putstr("processes are as far\n");
    my_putstr("away from each other as possible. ");
    my_putstr("The addresses are MEM_SIZE modulo.\n");
}