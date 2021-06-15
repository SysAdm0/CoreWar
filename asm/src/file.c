/*
** EPITECH PROJECT, 2021
** file
** File description:
** file
*/

#include "my.h"

bool is_file(char *filepath)
{
    FILE *fp = fopen(filepath, "r");

    if (fp == NULL)
        return false;
    if (my_strstr(filepath, ".s") == NULL)
        return false;
    fclose(fp);
    return true;
}

size_t get_file_size(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);

    lseek(fd, 0, SEEK_SET);
    close(fd);
    return size;
}

char *get_file_buffer(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = get_file_size(filepath);
    char *buf = malloc(sizeof(char) * size + 1);

    read(fd, buf, size);
    buf[size] = '\0';
    close(fd);
    return buf;
}