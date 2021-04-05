/*
** EPITECH PROJECT, 2020
** player_play.c
** File description:
** player plays fonctions matchstck
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/proto.h"

char **player_play(char **map, int size, int mem)
{
    t_matchstick game;

    my_putstr("Your turn:\n");
    do {
        do {
            my_putstr("Line: ");
            if (player_info(&game.del_match) == 84)
                return NULL;
        } while (good_line(game.del_line, size) != 0);
        my_putstr("Matches: ");
        if (player_info(&game.del_match) == 84)
            return NULL;
        game.del_match = count_match(game.del_line, map);
    } while (good_match(game.del_match, mem, game.mem_match) != 0);
    my_putstr("Player removed ");
    my_put_nbr(game.del_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(game.del_line);
    my_putchar('\n');
    map = remove_match(game.del_match, game.del_line, map);
    display(map);
    return map;
}

int player_info(int *res)
{
    int good;
    char buffer;
    char *info = malloc(sizeof(char));

    info[0] = '\0';
    for (buffer = '\0'; buffer != '\n'; buffer = buffer) {
        buffer = '\0';
        good = read(0, &buffer, 1);
        info = my_realloc_toread(info, buffer);
        if (good == 0)
            return 84;
    }
    *res = my_getread(info);
    free(info);
    return 0;
}

int good_line(int line, int size)
{
    if (line < 0) {
        my_putstr("Error: ");
        my_putstr("invalid output (positive number expected)\n");
        return 84;
    }
    if (line == 0 || line > size) {
        my_putstr("Error: ");
        my_putstr("this line is out of range\n");
       
        return 84;
    }
    return 0;
}

int good_match(int match, int mem, int delete_match)
{
    if (match < 0) {
        my_putstr("Error: ");
        my_putstr("invalid output (positive number expected)\n");
        return 84;
    }
    if (match == 0) {
        my_putstr("Error: ");
        my_putstr("you have to remove at least one match\n");
        return 84;
    }
    if (match > mem) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(mem);
        my_putstr(" matches per turn\n");
        return 84;
    }
    if (match > remove_match) {
        good_match_2();
        return 84;
    }
    return 0;
}

void good_match_2(void)
{
    my_putstr("Error: ");
    my_putstr("not enough matches on this line\n");
}
