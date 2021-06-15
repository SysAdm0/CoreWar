/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** header
*/

#ifndef _ASM_
#define _ASM_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "op.h"

enum type_e {
    OPCODE,
    LABEL,
    CMD
};

enum cmd_e {
    NAME,
    COMMENT
};

typedef struct lex_s {
    enum type_e type;
    char *code;
    int line;
    struct lex_s *next;
} lex_t;

typedef struct lab_info_s {
    char *name;
    int addr;
} lab_info_t;

typedef struct lab_s {
    int free;
    struct lab_info_s label[101];
    struct lab_s *next;
} lab_t;

// dashh.c
void dashh(void);
int checkh(char *dash);
int cmph(char *dash);

// my_asm.c
int my_asm(char *file);

// check_is.c
int is_space(char c);
int is_cmd(char *str, int size);
int is_digit(char c);
void is_valid(char *arg, char *mask, int i);

// file.c
bool is_file(char *filepath);
size_t get_file_size(char *filepath);
char *get_file_buffer(char *filepath);

// create_file.c
int create_file(char *name);

// lexer.c
lex_t *lex_get(void);
void lex_new(char *code, enum type_e type, int line);
void lex_free(void);

// check_lexer.c
lex_t *check_lexer(char *src);

// label.c
lab_t *lab_get(void);
void lab_new(lex_t *lex, int size);
void lab_free(void);

// check_label.c
void lab_check(lex_t *lex, char *label);
lab_info_t label_valid(lex_t *lex, int pos, char *label);

// cmd.c
void write_cmd(char *str);

// add_cmd.c
void add_cmd(char *str, int *pos, int line);

// add_label.c
void add_label(char *str, int *pos, int *line);

// add_opcode.c
void add_opcode(char *str, int *pos, int line);

// check_syntax.c
void check_syntax(lex_t *lex);

// check_syntax_args.c
void check_syntax_args(lex_t *lex, op_t op, int pos);

// opcode.c
op_t get_by_mnemo(char *name);
op_t get_by_code(char code);

// bytecode.c
void write_bytecode(char *file, int size);
void byte_add(char *mem, int size);
void byte_new(lex_t *lex);

// bytecode_arg.c
char *get_arg(char *code);
int byte_arg(lex_t *lex, op_t op, int pos);

// bytecode_size.c
int byte_size(lex_t *lex);

// bytecode_encode.c
int byte_encode(char *code);
int byte_if_encode(op_t op);

// compilation.c
int rev_indian(int n);
void compilation(char *file, lex_t *lex);

// header.c
void head_cmd(enum cmd_e cmd, char *str);
void head_size(int size);
void write_header(int fd);

// my_str_header.c
char *my_str_header(char *src, int size);

// mylib
void my_putchar_fd(char c, int fd);
void my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
char **my_str_word_array(char *str, char *delim);
void my_free_word_array(char **arr);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);
void my_memset(void *ptr, int value, size_t size);
void my_memcpy(void *dst, void *src, size_t size);
char *my_strstr(char *str, char const *to_find);
char *my_strchr(const char *str, char c);
int my_atoi(char *str);

#endif /* _ASM_ */
