/*
** EPITECH PROJECT, 2021
** Created by Lucien
** File description:
** get_pc.c
*/

#include "my.h"
#include <criterion/criterion.h>

int findMax(int decimal)
{
    int bitlength = 0;
    int mul = 1;

    while (decimal >= mul) {
        bitlength++;
        mul = mul*16;
    }
    if (bitlength == 0)
        bitlength = 1;
    return bitlength;
}

void convertDecimalToBinary(int decimal, char *arr, int max, char *hexavalues)
{
    int temp = 0;

    for (int i = 0; i < max; i++) {
        temp = decimal % 16;
        arr[max-1-i] = hexavalues[temp];
        decimal = decimal >> 4;
    }
}

char *convert_hexa_to_bin(int decimal)
{
    char hexavalues[16] = {'0', '1', '2', '3', '4', '5', '6',
                           '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int max = findMax(decimal);
    char *hex = malloc(sizeof(char) * max + 1);

    convertDecimalToBinary(decimal, hex, max, hexavalues);
    hex[max] = '\0';
    return (hex);
}

Test(convert_hexa_to_bin, unit_test)
{
    char *value = convert_hexa_to_bin(20);

    cr_assert_eq(value[0], '1');
    cr_assert_eq(value[1], '4');
}

Test(findMax, unit_test)
{
    int value = findMax(20);

    cr_assert_eq(value, 2);
}
