/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** is_alive
*/

#include "my.h"

char *is_alive(char *player)
{
    static char *save;

    if (player != NULL)
        save = player;
    return (save);
}

int is_alive_id(int id)
{
    static int save;

    if (id != 0)
        save = id;
    return (save);
}