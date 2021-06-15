/*
** EPITECH PROJECT, 2021
** my_asm
** File description:
** my_asm
*/

#include "my.h"

static char **get(void)
{
    static char *str = NULL;

    return &str;
}

int my_asm(char *file)
{
    char **buff = get();

    *buff = get_file_buffer(file);
    if (is_file(file) == false)
        return 84;
    if (get_file_size(file) == 0)
        return 84;
    check_syntax(check_lexer(*buff));
    compilation(file, lex_get());
    return 0;
}