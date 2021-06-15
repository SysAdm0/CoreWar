/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** openfile
*/

#include "my.h"

int get_file_size(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = lseek(fd, 0, SEEK_END);

    close(fd);
    return size;
}

int get_max_size(char **name)
{
    int fd = 0;
    int size = 0;
    int max = 0;

    for (int x = 0; name[x] != NULL; x++) {
        fd = open(name[x], O_RDONLY);
        size = lseek(fd, 0, SEEK_END);
        if (size > max)
            max = size;
        close(fd);
    }
    return (max);
}

char **openfile(char **name, champ_t *champ_s)
{
    size_t size = 0;
    int fp = 0;
    int file_size = 0;
    int stable_size = get_max_size(name);
    char **champ = malloc(sizeof(char *) * 4);
    char *buffer;

    if (name[0] == NULL)
        exit(84);
    for (int x = 0; x < 4; x++)
        champ[x] = malloc(sizeof(char) * stable_size + 2);
    for (int x = 0; name[x] != NULL; x++, size = 0) {
        file_size = get_file_size(name[x]);
        fp = open(name[x], O_RDONLY);
        buffer = malloc(sizeof(char) * stable_size + 2);
        read(fp, buffer, file_size);
        champ[x] = buffer;
        champ_s->sz = champ_s->sz + 1;
        champ_s->size[x] = file_size;
        close(fp);
    } return (champ);
}