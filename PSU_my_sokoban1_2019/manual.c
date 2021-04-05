/*
** EPITECH PROJECT, 2019
** manual.c
** File description:
** manual -h
*/

#include <stdio.h>
void my_putchar(char c);
int my_putstr(char const *str);

void manual(void)
{
    my_putstr("USAGE\n");
    my_putstr("    ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("    map  file representing the warehouse map, containing '#' for walls,\n");
    my_putstr( "        'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
}
