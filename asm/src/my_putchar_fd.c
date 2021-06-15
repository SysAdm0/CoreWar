/*
** EPITECH PROJECT, 2021
** my_putchar_fd
** File description:
** my_putchar_fd
*/

#include <unistd.h>

void my_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}