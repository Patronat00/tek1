/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** dislay map matchstick
*/

#include <stddef.h>
#include "../include/proto.h"

void display(char **map)
{
    int count;

    for (count = 0; map[count] != NULL; count++){
        my_putstr(map[count]);
        my_putchar('\n');
    }
    my_putchar('\n');
}
