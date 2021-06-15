/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** error_handling
*/

#include "my.h"

void is_number_args(char *str, char *param)
{
    char message1[] = ": invalid parameter.\n";
    char message2[] = "The parameter must be greater than 0.\n";
    int size = 0;
    int nb = 0;

    if (str == NULL) {
        for (; param[size] != '\0'; size++);
        write(1, param, size);
        write(1, message1, sizeof(message1));
        exit(84);
    } for (int x = 0; str[x] != '\0'; x++) {
        if (str[x] < '0' || str[x] > '9') {
            for (; param[size] != '\0'; size++);
            write(1, param, size);
            write(1, message1, sizeof(message1));
            exit(84);
        } nb = nb * 10 + (str[x] - 48);
    } if (nb <= 0) {
        write(1, message2, sizeof(message2));
        exit(84);
    }
}

void invalid_arg(char *str)
{
    char message[] = ": invalid argument.\n";
    int size = 0;

    if (my_strcmp(str, "-dump") == 0 &&
        my_strcmp(str, "-n") == 0 && my_strcmp(str, "-a") == 0 &&
        my_strcmp(str, "-g") == 0) {
        for (; str[size] != '\0'; size++);
        write(1, str, size);
        write(1, message, sizeof(message));
        exit(84);
    }
}

void double_def(error_t error)
{
    int stop = 0;

    if (error.dump > 1) {
        write(1, "Double definition of option dump.\n", 34);
        stop = 1;
    } if (error.n > 1 && stop == 0) {
        write(1, "Double definition of -n option.\n", 32);
        stop = 1;
    } if (error.a > 1 && stop == 0) {
        write(1, "Double definition of -a option.\n", 32);
        stop = 1;
    } if (error.g > 1 && stop == 0) {
        write(1, "Double definition of -g option.\n", 32);
        stop = 1;
    } if (stop == 1)
        exit(84);
}

int check_args(int argc, char **argv)
{
    error_t error = {0, 0, 0, 0};

    for (int x = 0; x < argc; x++) {
        if (argv[x][0] == '-') {
            if (my_strcmp(argv[x], "-dump") == 1) {
                is_number_args(argv[x + 1], argv[x]);
                error.dump += 1;
            } if (my_strcmp(argv[x], "-n") == 1) {
                is_number_args(argv[x + 1], argv[x]);
                error.n += 1;
            } if (my_strcmp(argv[x], "-a") == 1) {
                is_number_args(argv[x + 1], argv[x]);
                error.a += 1;
            } if (my_strcmp(argv[x], "-g") == 1)
                error.g += 1;
            invalid_arg(argv[x]);
        }
    } double_def(error);
}