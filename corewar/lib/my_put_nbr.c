/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** print number
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        my_put_nbr(nb);
    } else if (nb > 10) {
        modulo = nb % 10;
        nb /= 10;
        my_put_nbr(nb);
        my_put_nbr(modulo);
    } else {
        if (nb == 10) {
            my_putchar('1');
            my_putchar('0');
        } else
            my_putchar(nb + 48);
    }
}
