/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** parse_file
*/

#include "my.h"

char *my_new_str(char *str, int begin, int end)
{
    int size = 0;
    int add = 0;
    char *champ;

    for (int i = begin; i < end; i++, size++);
    champ = malloc(sizeof(char) * size + 1);
    for (int i = begin; i < end; i++)
        champ[add++] = str[i];
    free(str);
    return (champ);
}

char **parse_file(char **champ, champ_t *ch)
{
    int i = 0;

    for (int x = 0; x < ch->sz; x++) {
        for (; champ[x][i] != '\0'; i++);
        for (; champ[x][i] == 0; i++);
        for (; champ[x][i] != '\0'; i++);
        for (; champ[x][i] == 0; i++);
        for (; champ[x][i] != '\0'; i++);
        for (; champ[x][i] == 0; i++);
        champ[x] = my_new_str(champ[x], i, ch->size[x]);
        ch->size[x] = ch->size[x] - i;
        i = 0;
    }
    return (champ);
}