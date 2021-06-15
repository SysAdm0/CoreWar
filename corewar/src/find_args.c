/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** find_args
*/

#include "my.h"

args_s find_args(char **argv, args_s args)
{
    for (int x = 0; argv[x] != NULL; x++) {
        if (argv[x][0] == '-') {
            if (my_strcmp(argv[x], "-dump") == 1) {
                args.nbr_cycle = my_atoi(argv[x + 1]);
            } if (my_strcmp(argv[x], "-n") == 1) {
                args.prog_number = my_atoi(argv[x + 1]);
            } if (my_strcmp(argv[x], "-a") == 1) {
                args.load_address = my_atoi(argv[x + 1]);
            } if (my_strcmp(argv[x], "-g") == 1) {
                args.graphical = my_atoi(argv[x + 1]);
            }
        }
    }
    return (args);
}