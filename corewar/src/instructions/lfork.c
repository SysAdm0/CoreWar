/*
** EPITECH PROJECT, 2020
** fork
** File description:
** example of bad code:
*/
#include "my.h"

cha_t *copy_struct_lfork(cha_t *champ, cha_t *new, int index)
{
    new->player_name = champ->player_name;
    new->pc = champ->pc + index;
    new->init_pc = new->pc;
    new->carry = champ->carry;
    new->player_id = champ->player_id;
    new->cycle = 0;
    new->player_status = champ->player_status;
    return (new);
}

int lfork(cha_t *champ, instruction_t *inst)
{
    int *params;
    cha_t *element = malloc(sizeof(cha_t));
    cha_t *temp;

    champ->cycle = 0;
    params = get_params(inst->vm, champ->pc + 1);
    if (params[0] != 1 || params[4] - params[1] != 2)
        return 1;
    element = copy_struct_lfork(champ, element, params[1]);
    temp = champ->next;
    champ->next = element;
    element->next = temp;
    get_players(get_players(0) + 1);
    return (0);
}