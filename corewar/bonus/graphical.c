/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** graphical
*/

#include "my.h"
#include <curses.h>

void header()
{
    move(0, 76);
    printw("_________                      __      __               \n");
    move(1, 76);
    printw("\\_   ___ \\  ___________   ____/  \\    /  \\_____ _______\n");
    move(2, 76);
    printw("/    \\  \\/ /  _ \\_  __ \\_/ __ \\   \\/\\/   /\\__  \\\\_  __ \\\n");
    move(3, 76);
    printw("\\     \\___(  <_> )  | \\/\\  ___/\\        /  / __ \\|  | \\/\n");
    move(4, 76);
    printw(" \\______  /\\____/|__|    \\___  >\\__/\\  /  (____  /__|   \n");
    move(5, 76);
    printw("        \\/                   \\/      \\/        \\/       \n");
}

void fill_footer_p2(int line, int *size, int sz)
{
    move(line + 2, 95);
    printw("PLAYER 2");
    move(line + 4, 94);
    if (sz > 1) {
        printw("Live -> yes");
        move(line + 5, 94);
        printw("Size -> %d", size[1]);
    } else {
        printw("Live -> --");
        move(line + 5, 94);
        printw("Size -> --");
    }
    move(line + 2, 135);
    printw("PLAYER 3");
    move(line + 4, 134);
    if (sz > 2) {
        printw("Live -> yes");
        move(line + 5, 134);
        printw("Size -> %d", size[2]);
    } else {
        printw("Live -> --");
        move(line + 5, 134);
        printw("Size -> --");
    }
    move(line + 2, 175);
    printw("PLAYER 4");
    move(line + 4, 174);
    if (sz > 3) {
        printw("Live -> yes");
        move(line + 5, 174);
        printw("Size -> %d", size[3]);
    } else {
        printw("Live -> --");
        move(line + 5, 174);
        printw("Size -> --");
    }
}

void fill_footer(int line, int *size, int sz, int c1, int c2)
{
    move(line + 2, 1);
    printw("CURRENT CYCLE : %d", c2);
    move(line + 3, 1);
    printw("CYCLES NUMBER : %d", c1);
    move(line + 4, 1);
    printw("CHAMPIONS ALIVE : %d", sz);
    move(line + 5, 1);
    printw("CHAMPIONS NUMBER : %d", sz);
    move(line + 2, 55);
    printw("PLAYER 1");
    move(line + 4, 54);
    if (sz > 0) {
        printw("Live -> yes");
        move(line + 5, 54);
        printw("Size -> %d", size[0]);
    } else {
        printw("Live -> --");
        move(line + 5, 54);
        printw("Size -> --");
    }
    fill_footer_p2(line, size, sz);
}

void footer(int line, int *size, int sz, int c1, int c2)
{
    for (int x = 0; x < 6; x++) {
        for (int y = 0; y <= 199; y++) {
            if (x == 0 || x == 5)
                addch('-');
            else if (y == 0 || y == 40 || y == 80 || y == 120 || y == 160 || y == 199)
                addch('|');
            else
                addch(' ');
        }
        addch('\n');
    }
    fill_footer(line, size, sz, c1, c2);
    refresh();
}

void graphical(int *vm, int *size, int sz, int c1, int c2)
{
    int add_line = 0;
    int line = 5;
    char *str;

    initscr();
    header();
    refresh();
    for (int x = 0; x < MEM_SIZE - 3084; x++, add_line++) {
        if (add_line == 68) {
            addch('\n');
            line++;
            add_line = 0;
        } else {
            str = convert_hexa_to_bin(vm[x]);
            if (wordlen(str) != 1)
                printw(str);
            else {
                printw(str);
                addch('0');
            }
            addch(' ');
        }
        refresh();
    }
    addch('\n');
    refresh();
    footer(line + 1, size, sz, c1, c2);
    refresh();
}