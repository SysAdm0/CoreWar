/*
** EPITECH PROJECT, 2021
** inst.h
** File description:
** header
*/

#ifndef _INST_
#define _INST_

int add(cha_t *champ, instruction_t *inst);
int and(cha_t *champ, instruction_t *inst);
int aff(cha_t *champ, instruction_t *inst);
int func_fork(cha_t *champ, instruction_t *inst);
int ld(cha_t *champ, instruction_t *inst);
int ldi(cha_t *champ, instruction_t *inst);
int lfork(cha_t *champ, instruction_t *inst);
int live(cha_t *champ, instruction_t *inst);
int lld(cha_t *champ, instruction_t *inst);
int lldi(cha_t *champ, instruction_t *inst);
int or(cha_t *champ, instruction_t *inst);
int st(cha_t *champ, instruction_t *inst);
int sti(cha_t *champ, instruction_t *inst);
int sub(cha_t *champ, instruction_t *inst);
int xor(cha_t *champ, instruction_t *inst);
int zjmp(cha_t *champ, instruction_t *inst);

#endif /* _INST_ */