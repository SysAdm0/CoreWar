/*
** EPITECH PROJECT, 2021
** bytecode.c
** File description:
** bytecode
*/

#include "my.h"

static char **get(void)
{
    static char *bytecode = NULL;

    return &bytecode;
}

void write_bytecode(char *file, int size)
{
    int fd = create_file(file);

    if (fd == -1)
        exit(84);
    write_header(fd);
    write(fd, *(get()), size);
    free(*get());
    close(fd);
}

void byte_add(char *mem, int size)
{
    static int pos = 0;
    static int maxsize = 1024;
    int i = 0;
    char **bytecode = get();

    if (*bytecode == NULL)
        *bytecode = malloc(sizeof(char) * (maxsize + 1));
    if (pos + size >= maxsize) {
        maxsize += 1024;
        *bytecode = realloc(*bytecode, sizeof(char) * (maxsize + 1));
    }
    for (; i < size; i++)
        (*bytecode)[pos + i] = mem[i];
    pos += size;
}

void byte_new(lex_t *lex)
{
    static int pos = 0;
    op_t op;
    int i = 0;

    for (; !is_space(lex->code[i]); i++);
    lex->code[i] = '\0';
    op = get_by_mnemo(lex->code);
    lex->code[i] = ' ';
    byte_add(&op.code, 1);
    for (; is_space(lex->code[i]); i++);
    if (byte_if_encode(op))
        byte_encode(&lex->code[i]);
    pos += byte_arg(lex, op, pos);
    pos += (byte_if_encode(op)) ? 2 : 1;
}