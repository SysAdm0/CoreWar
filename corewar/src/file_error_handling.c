/*
** EPITECH PROJECT, 2021
** undefined
** File description:
** file_error_handling
*/
#include "my.h"

int check_empty_file(char **filepath)
{
    for (int i = 0; filepath[i] != NULL; i++) {
        if (get_file_size(filepath[i]) == 0)
            return 84;
    } return 0;
}

int check_file_exist(char **filepath)
{
    int fd = 0;

    for (int i = 0; filepath[i] != NULL; i++) {
        fd = open(filepath[i], O_RDONLY);
        if (fd == -1) {
            close(fd);
            return 84;
        } close(fd);
    } return 0;
}