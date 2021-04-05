/*
** EPITECH PROJECT, 2020
** match_fonct.c
** File description:
** match fonctions mathstick
*/

#include "../include/proto.h"

int count_match(int line, char **map)
{
    int count = 0;
    int i;

    for(i = 0; map[line][i] != '\0'; i++)
        if (map[line][i] == '|')
            count++;
    return (count);
}

char **remove_match(int match, int line, char **map)
{
    int count;

    for (count = my_strlen(map[line]); count != 0; count--) {
        if(map[line][count] == '|' && match != 0) {
            map[line][count] = ' ';
            match--;
        }
        if (match == 0)
            return map;
    }
    return NULL;
}

int lose(char **map)
{
    int y_axis = 1;

    for (y_axis = 1; map[y_axis] != NULL; y_axis++) {
        if (count_match(y_axis, map) != 0)
            return 84;
    }
    return 0;
}
