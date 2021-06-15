/*
** EPITECH PROJECT, 2020
** task01
** File description:
** example of bad code:
*/

#include "my.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}