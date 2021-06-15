/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_players
*/

#include "my.h"

int get_players(int nb)
{
    static int players;

    if (nb != 0)
        players = nb;
    return (players);
}