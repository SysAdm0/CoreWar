/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** live
*/

#include "my.h"

void player_live(char *name, int id)
{
    my_putstr("The player ");
    my_putstr(name);
    my_putchar('(');
    my_put_nbr(id);
    my_putchar(')');
    my_putstr("is alive.\n");
}

int live(cha_t *champ, instruction_t *inst)
{
    char *name = champ->player_name;
    int id = champ->player_id;

    champ->cycle = 0;
    if (id < 0 || id > 3)
        return (1);
    champ->player_status = 1;
    player_live(name, id);
    champ->pc = get_pc(NULL, champ->pc + T_IND + 1, champ->pc);
    is_alive(name);
    is_alive_id(id);
    return (0);
}