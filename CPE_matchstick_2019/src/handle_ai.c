/*
** EPITECH PROJECT, 2020
** handle.ai.c
** File description:
** handle ai focntions
*/

#include <stdlib.h>
#include <stdlib.h>
#include "../include/proto.h"

char **ai_play(char **map, int size, int mem)
{
    t_matchstick game;

    my_putstr("AI's turn...\n");
    do {
        do {
            game.del_line = random()/1000000;
        } while (good_line_ai(game.del_line, size) != 0);
        game.del_match = random()/1000000;
        game.mem_match = count_match(game.del_line, map);
    } while (good_match_ai(game.del_match, mem, game.mem_match) != 0);
    my_putstr("AI removed ");
    my_put_nbr(game.del_match);
    my_putstr(" match(es) from line ");
    my_put_nbr(game.del_line);
    my_putchar('\n');
    map = remove_match(game.del_match, game.del_line, map);
    display(map);
    return map;
}

int good_line_ai(int line, int size)
{
    if (line < 0)
        return 84;
    if (line == 0 || line > size)
        return 84;
    return 0;
}

int good_match_ai(int match, int mem, int cancel_match)
{
    if (match < 0)
        return 84;
    if (match == 0)
        return 84;
    if (match > mem)
        return 84;
    if (match > cancel_match)
        return 84;
    return 0;
}

int safe(int size)
{
    int r = rand();

    while (r > 0 && r < size)
        r = rand();
    return r;
}