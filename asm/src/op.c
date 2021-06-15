/*
** EPITECH PROJECT, 2021
** op
** File description:
** op
*/

#include "op.h"

op_t op_tab[] = {
    {"live", 4, 1, {T_DIR}, 1, 10, "alive"},
    {"ld", 4, 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
    {"st", 0, 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
    {"add", 0, 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
    {"sub", 0, 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
    {"and", 4, 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "et (and  r1, r2, r3   r1&r2 -> r3"},
    {"or", 4, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "ou  (or   r1, r2, r3   r1 | r2 -> r3"},
    {"xor", 4, 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "ou (xor  r1, r2, r3   r1^r2 -> r3"},
    {"zjmp", 2, 1, {T_DIR}, 9, 20, "jump if zero"},
    {"ldi", 2, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index"},
    {"sti", 2, 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index"},
    {"fork", 2, 1, {T_DIR}, 12, 800, "fork"},
    {"lld", 4, 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
    {"lldi", 2, 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index"},
    {"lfork", 2, 1, {T_DIR}, 15, 1000, "long fork"},
    {"aff", 0, 1, {T_REG}, 16, 2, "aff"},
    {0, 0, 0, {0}, 0, 0, 0}
};