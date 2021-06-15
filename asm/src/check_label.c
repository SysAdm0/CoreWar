/*
** EPITECH PROJECT, 2021
** check_label
** File description:
** check_label
*/

#include "my.h"

void lab_check(lex_t *lex, char *label)
{
    int i = 0;
    lab_t *lab = lab_get();

    for (; lab; lab = lab->next) {
        i = 0;
        for (; lab->label[i].name != NULL; i++)
            if (my_strcmp(lab->label[i].name, label) == 0)
                exit(84);
    }
}

lab_info_t label_valid(lex_t *lex, int pos, char *label)
{
    int i = 0;
    lab_t *lab = lab_get();
    lab_info_t bad;

    bad.name = NULL;
    bad.addr = 0;
    for (; lab; lab = lab->next) {
        i = 0;
        for (; lab->label[i].name != NULL &&
            my_strcmp(lab->label[i].name, label) != 0; i++);
        if (my_strcmp(lab->label[i].name, label) == 0)
            return lab->label[i];
    }
    exit(84);
    return bad;
}