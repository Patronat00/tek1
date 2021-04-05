/*
** EPITECH PROJECT, 2020
** my_memeset.c
** File description:
** my_memset 
*/

#include "my.h"

char *my_memset(char *str, char c, int size)
{
    int count;

    for (count = 0; count < size; count++)
        str[count] = c;
        str[count] = '\0';
    return str;
}
