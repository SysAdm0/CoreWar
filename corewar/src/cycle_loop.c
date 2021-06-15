/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** cycle_loop
*/

#include "my.h"

void player_win(char *name, int id)
{
    my_putstr("The player ");
    my_putstr(name);
    my_putchar('(');
    my_put_nbr(id);
    my_putchar(')');
    my_putstr("has won.\n");
}

int cycle_loop(args_s *args, cha_t *champ, champ_t siz, instruction_t *inst)
{
    int players = 0;

    for (int x = 0; x < args->nbr_cycle; x++) {
        players = get_players(0);
        for (int y = 0; y <= players; y++, champ = champ->next) {
            call_instructions(champ, inst);
            champ->cycle = champ->cycle + 1;
            if (champ->pc - champ->init_pc >= siz.size[champ->player_id - 1])
                champ->pc = champ->init_pc;
            if (champ->pc < 0)
                champ->pc = champ->init_pc * -1;
            champ->pc = champ->pc % MEM_SIZE;
        }
        if (args->graphical)
            graphical(inst->vm, siz.size, siz.sz, args->nbr_cycle, x);
    }
    if (is_alive(NULL) != NULL)
        player_win(is_alive(NULL), is_alive_id(0));
    return 0;
}