/*
** EPITECH PROJECT, 2021
** create_file
** File description:
** create_file
*/

#include "my.h"

char *new_file_name(char *filename)
{
    char *new_name = malloc(my_strlen(filename) + 2);

    my_memcpy(new_name, filename, my_strlen(filename) - 2);
    new_name[my_strlen(filename) - 2] = '\0';
    my_strcat(new_name, ".cor");
    return new_name;
}

int create_file(char *name)
{
    char *new_name = new_file_name(name);
    int hfile = open(new_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (hfile == -1)
        return -1;
    return hfile;
}