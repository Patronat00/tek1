/*
** EPITECH PROJECT, 2019
** dec_to_hexa.c
** File description:
** decimal to hexa
*/
#include<stdio.h>
#include <math.h>

void my_putchar(char c);

int decToHexa(int nb)
{
    int number_1, remainder;
    int i, j = 0;
    char hexadecimal[100];

    number_1 = nb;
    while (nb != 0) {
        remainder = nb % 16;
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;
        else
            hexadecimal[j++] = 55 + remainder;
        nb = nb / 16;
    }
    for (i = j; i >= 0; i--)
        my_putchar(hexadecimal[i]);
    return 0;
}