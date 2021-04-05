/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main matchstick
*/

#include "../include/proto.h"

int main (int ac, char **av)
{
    int size;
    int mem;
    char **map;

    if (ac != 3)
        return 84;
    size = my_getnbr(av[1]);
    mem = my_getnbr(av[2]);
    if (size == 0)
        return 84;
    if (size < 1 || size > 99)
        return 84;
    if (mem == 0 && mem < 1)
        return 84;
    map = go_map(size);
    map = go_match(size, map);
    display(map);
    mem = game(map, size, mem);
    if (mem == 84) {
        my_putchar('\n');
        return 0;
    }
    map_free(map, size);
    return mem;
}
