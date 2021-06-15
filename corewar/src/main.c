/*
** EPITECH PROJECT, 2021
** main
** File description:
** corewar
*/

#include "my.h"

char **my_name(char **argv)
{
    char **name = find_champions(argv);

    if (checkfilename(name) == 84 || check_file_exist(name) == 84
    || check_empty_file(name) == 84)
        exit(84);
    return (name);
}

int err_handling(char **argv, int argc)
{
    if ((argc == 2 && checkh(argv[1]) == 0) || argc == 1)
        dashh();
    else if (check_args(argc, argv) == 84)
        exit(84);
    else
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    args_s args = {0, 0, 0, 0};
    champ_t champ = {malloc(sizeof(int) * 4),  0, 0};
    instruction_t inst;
    char **champions;
    char **name;
    cha_t *cha;
    int addr = 0;

    if (err_handling(argv, argc) == 1) {
        name = my_name(argv);
        args = find_args(argv, args);
        champions = openfile(name, &champ);
        champions = parse_file(champions, &champ);
        addr = load_address(champions, champ, args);
        champ.addr = addr;
        cha = fill_champ(cha, champions, name, champ);
        inst.vm = create_vm(champions, addr, champ, args);
        get_players(args.prog_number);
        cycle_loop(&args, cha, champ, &inst);
    }
    return (0);
}