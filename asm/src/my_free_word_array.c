/*
** EPITECH PROJECT, 2020
** lib/my/my_free_word_array
** File description:
** my_free_word_array
*/

#include <stdlib.h>

void my_free_word_array(char **arr)
{
    if (arr == NULL)
        return;
    for (int i = 0; arr[i] != NULL; i++)
        free(arr[i]);
    free(arr);
}