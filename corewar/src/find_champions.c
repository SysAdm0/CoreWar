/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** find_champions
*/

#include "my.h"

char **my_malloc(int x, char **argv)
{
    char **champions;
    int max = 0;
    int add = 0;

    for (int i = 1; argv[i] != NULL; i++) {
        for (add = 0; argv[i][add] != '\0'; add++);
        if (add > max)
            max = add;
    } champions = malloc(sizeof(char *) * x + 2);
    for (int i = 0; i < x; i++)
        champions[i] = malloc(sizeof(char) * max + 2);
    return (champions);
}

char **find_champions(char **argv)
{
    char **champions;
    int args = 1;

    for (int x = 1; argv[x] != NULL; x++) {
        if (my_strcmp(argv[x], "-g") == 1)
            continue;
        else if (argv[x][0] == '-')
            x += 1;
        else
            args++;
    } champions = my_malloc(args, argv);
    args = 0;
    for (int x = 1; argv[x] != NULL; x++) {
        if (my_strcmp(argv[x], "-g") == 1)
            continue;
        else if (argv[x][0] == '-')
            x += 1;
        else
            champions[args++] = argv[x];
    } champions[args] = NULL;
    return (champions);
}