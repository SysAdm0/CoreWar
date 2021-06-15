/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** header
*/

#ifndef _COREWAR_
#define _COREWAR_

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "op.h"
#include "struct.h"
#include "inst.h"

void call_instructions(cha_t *champ, instruction_t *inst);
int champlen(char *str);
int check_args(int argc, char **argv);
int check_empty_file(char **filepath);
int checkfilename(char **champ);
int check_file_exist(char **filepath);
int checkh(char *dash);
int cmph(char *dash);
char *convert_hexa_to_bin(int decimal);
void convert_vm_to_hexa(instruction_t inst);
int *create_vm(char **champ, int addr, champ_t ch, args_s args);
int cycle_loop(args_s *args, cha_t *champ, champ_t siz, instruction_t *inst);
void dashh(void);
void graphical(int *vm, int *size, int sz, int c1, int c2);
int get_file_size(char *filepath);
int get_pc(int *tab, int no_occ, int pc);
cha_t *fill_champ(cha_t *champ, char **champions, char **name, champ_t value);
int get_players(int nb);
void my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr(int nb);
void print_vm(int *vm);
int my_atoi(char *str);
int my_strcmp(char *str1, char *str2);
char *my_strdup(char const *str);
char *is_alive(char *player);
int is_alive_id(int id);
int is_register(int *params, int nb);
int is_index(int *params, int nb);
int p_type(int *params, int nb);
int load_address(char **champ, champ_t ch, args_s args);
int find_next_opcode(int pc, instruction_t *inst);
int params_value(int *vm, int start, int end);
int *get_params(int *vm, int ocp);
char **find_champions(char **argv);
char **openfile(char **name, champ_t *champ_s);
char **parse_file(char **champ, champ_t *ch);
args_s find_args(char **argv, args_s args);
int wordlen(char const *str);

#endif /* _COREWAR_ */