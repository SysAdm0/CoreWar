/*
** EPITECH PROJECT, 2021
** label
** File description:
** label
*/

#include "my.h"

static lab_t **get(void)
{
    static lab_t *label = NULL;

    return &label;
}

static void new(char *label, int size)
{
    lab_t **lab = get();
    lab_t *tmp;
    lab_t *new = malloc(sizeof(lab_t));

    new->label[0].name = label;
    new->label[0].addr = size;
    new->label[1].name = NULL;
    new->free = 1;
    new->next = NULL;
    if (*lab == NULL) {
        *lab = new;
    } else {
        tmp = lab_get();
        while (tmp && tmp->next)
            tmp = tmp->next;
        tmp->next = new;
    }
}

lab_t *lab_get(void)
{
    return *(get());
}

void lab_new(lex_t *lex, int size)
{
    lab_t *lab = lab_get();
    char *label = NULL;
    int i = 0;

    for (; lex->code[i] != LABEL_CHAR; i++);
    lex->code[i] = '\0';
    label = lex->code;
    lab_check(lex, lex->code);
    for (; lab && lab->free == 0; lab = lab->next);
    if (lab == NULL) {
        new(label, size);
    } else {
        i = 0;
        for (; lab->label[i].name != NULL; i++);
        lab->label[i].name = lex->code;
        lab->label[i].addr = size;
        lab->label[i + 1].name = NULL;
        lab->free = (i + 1 == 100) ? 0 : 1;
    }
}

void lab_free(void)
{
    lab_t *lab = lab_get();
    lab_t *tmp;

    while (lab) {
        tmp = lab;
        lab = lab->next;
        free(tmp);
    }
}