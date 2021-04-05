/*
** EPITECH PROJECT, 2020
** map_free.c
** File description:
** matchstick
*/

#include <stdlib.h>
#include "../include/proto.h"

void map_free(char **map, int size)
{
    int count;

    free(map[0]);
    for (count = 1; count < (size + 2); count++)
        free(map[count]);
    free(map);
}
