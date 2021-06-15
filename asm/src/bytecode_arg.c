/*
** EPITECH PROJECT, 2021
** bytecode_arg
** File description:
** bytecode_arg
*/

#include "my.h"

static int encode_reg(char *arg)
{
    char n = 0;

    arg++;
    n = (char)my_atoi(arg);
    byte_add(&n, 1);
    return 0;
}

static int encode_val(char *arg, op_t op)
{
    int n = 0;
    int label_sz = 2;

    if (*arg == DIRECT_CHAR) {
        label_sz = op.size;
        arg++;
    }
    n = my_atoi(arg);
    n = rev_indian(n);
    if (label_sz == 2)
        n = n >> 16;
    byte_add((char *)&n, label_sz);
    return label_sz;
}

static int encode_label(op_t op, lex_t *lex, int pos, int align)
{
    lab_info_t label;
    int i = 0;
    char tmp = 0;
    char *arg = get_arg(lex->code);

    arg = &arg[pos];
    if (*arg == DIRECT_CHAR)
        arg++;
    else
        op.size = 2;
    for (; arg[i] && arg[i] != SEPARATOR_CHAR && !is_space(arg[i]); i++);
    tmp = arg[i];
    arg[i] = '\0';
    arg[i] = tmp;
    label = label_valid(lex, pos, &arg[1]);
    i = rev_indian(label.addr - align);
    if (op.size == 2)
        i = i >> 16;
    byte_add((char *)&i, op.size);
    return op.size;
}

char *get_arg(char *code)
{
    int i = 0;

    for (; !is_space(code[i]); i++);
    for (; is_space(code[i]); i++);
    return &code[i];
}

int byte_arg(lex_t *lex, op_t op, int pos)
{
    char *code = get_arg(lex->code);
    int i = 0;
    int size = 0;

    for (; code[i]; i++) {
        if (i == 0 || code[i - 1] == SEPARATOR_CHAR) {
            if (code[i] == 'r') {
                size += encode_reg(&code[i]);
            } else {
                if (code[i] == LABEL_CHAR || code[i + 1] == LABEL_CHAR)
                    size += encode_label(op, lex, i, pos);
                else
                    size += encode_val(&code[i], op);
            }
        }
    }
    return size;
}