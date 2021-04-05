/*
** EPITECH PROJECT, 2020
** game.c
** File description:
** game matchstick
*/

#include "../include/proto.h"

int game(char **map, int size, int mem)
{
    while (1337) {
        map = player_play(map, size, mem);
        if (map == NULL)
            return 84;
        if (lose(map) == 0) {
            my_putstr("You lost, too bad...\n");
            return 2;
        }
        map = ai_play(map, size, mem);
        if (map == NULL)
            return 84;
        if (lose(map) == 0) {
            my_putstr("I lost... snif... but I'll get you next time!!\n");
            return 1;
        }
    }
}
