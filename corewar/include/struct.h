/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** header
*/

#ifndef _STRUCT_
#define _STRUCT_

typedef struct error_t {
    int dump;
    int n;
    int a;
    int g;
} error_t;

typedef struct champ_t {
    int *size;
    int sz;
    int addr;
} champ_t;

typedef struct cha_t {
    char *player_name;
    int pc;
    int init_pc;
    int carry;
    int cycle;
    int player_id;
    int player_status;
    char *champ;
    struct cha_t *next;
} cha_t;

typedef struct instruction_t {
    int *vm;
} instruction_t;

typedef struct args_s {
    int nbr_cycle;
    int prog_number;
    int load_address;
    int graphical;
} args_s;

#endif /* _STRUCT_ */