/*
** EPITECH PROJECT, 2020
** fill_struct_champ
** File description:
** example of bad code:
*/

#include "my.h"

cha_t *putinlistfront(cha_t *list, char *name, char *champ, int i)
{
    cha_t *element = malloc(sizeof(cha_t));

    element->player_name = name;
    element->champ = champ;
    element->pc = 0;
    element->carry = 0;
    element->cycle = 0;
    element->player_status = 0;
    element->player_id = i + 1;
    if (i == 0)
        return (element);
    element->next = list;
    return (element);
}

cha_t *fill_pc(cha_t *champ, champ_t value)
{
    int temp = 0;

    for (int i = 0; value.sz > i; i++) {
        if (i == 0) {
            champ->init_pc = 0;
            champ->pc = 0;
        } else {
            champ->pc = value.size[i - 1] + value.addr + temp;
            champ->init_pc = champ->pc;
        }
        temp  = champ->pc;
        champ = champ->next;
    }
    return champ;
}

cha_t *fill_champ(cha_t *champ, char **champions, char **name, champ_t value)
{
    cha_t *temp;

    for (int i = 0; name[i] != NULL; i++) {
        champ = putinlistfront(champ, name[i], champions[i], i);
        if (i == 0)
            temp = champ;
    }
    temp->next = champ;
    champ = temp;
    champ = fill_pc(champ, value);
    return (champ);
}