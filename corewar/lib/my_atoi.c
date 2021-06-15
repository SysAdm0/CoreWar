/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int nb = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] < '0' || str[x] > '9')
            return (-1);
        nb = nb * 10 + (str[x] - 48);
    }
    return (nb);
}