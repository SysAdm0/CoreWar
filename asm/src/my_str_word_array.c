/*
** EPITECH PROJECT, 2020
** my_str_word_array
** File description:
** my_str_word_array
*/

#include <stdbool.h>
#include <stdlib.h>

static bool check_delim(char to_cmp, char *delim)
{
    for (int i = 0; delim[i]; ++i)
        if (to_cmp == delim[i])
            return (true);
    return (false);
}

static int delim_words(char *str, char *delim)
{
    int result = 0;

    for (int i = 0; str[i]; ++i) {
        if (str[i] == '\n')
            continue;
        if (str[i] && check_delim(str[i], delim) == false) {
            result++;
            while (str[i] && check_delim(str[i], delim) == false)
                i++;
        }
        if (!str[i])
            break;
    }
    return (result);
}

static int l_words(char *str, char *delim)
{
    int count = 0;

    for (int i = 0; check_delim(str[i], delim) == false && str[i]; ++i)
        count++;
    return (count);
}

char **my_str_word_array(char *str, char *delim)
{
    int nb = delim_words(str, delim);
    char **tab = malloc(sizeof(char *) * (nb + 1));
    int i = 0;
    int j = 0;
    int count = 0;

    if (tab == NULL)
        return (NULL);
    while (j < nb) {
        while (check_delim(str[i], delim) == true)
            i++;
        count = 0;
        tab[j] = malloc(sizeof(char) * (l_words(str + i, delim) + 1));
        while (check_delim(str[i], delim) == false && str[i])
            tab[j][count++] = str[i++];
        tab[j++][count] = '\0';
    }
    tab[j] = NULL;
    return (tab);
}