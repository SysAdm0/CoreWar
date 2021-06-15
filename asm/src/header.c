/*
** EPITECH PROJECT, 2021
** header
** File description:
** header
*/

#include "my.h"

static header_t *get(void)
{
    static header_t header = {COREWAR_EXEC_MAGIC, {0}, 0, {0}};

    return &header;
}

void head_cmd(enum cmd_e cmd, char *str)
{
    int i = 0;
    int j = 0;
    header_t *head = get();

    for (; str[i] != '"'; i++);
    i++;
    for (; str[i + j] != '"'; j++);
    str[i + j] = '\0';
    if (cmd == NAME)
        my_strcpy(head->prog_name, my_str_header(&str[i], PROG_NAME_LENGTH));
    else if (cmd == COMMENT)
        my_strcpy(head->comment, my_str_header(&str[i], COMMENT_LENGTH));
}

void head_size(int size)
{
    header_t *head = get();

    head->prog_size = size;
}

void write_header(int fd)
{
    write(fd, (void *)get(), sizeof(header_t));
}