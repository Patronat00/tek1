/*
** EPITECH PROJECT, 2020
** go_map.c
** File description:
** generate map for matchstick
*/

#include <stddef.h>
#include <stdlib.h>
#include "../include/proto.h"
#include "../lib/my/my.h"

char **map_memory(int size)
{
    char **map;
    int count = 0;

    map = malloc(sizeof(char *) * (size + 3));
    for (count = 0; count < (size + 2); count++) {
        map[count] = malloc(sizeof(char) * (size + 2) + 3);
    }
    map[count] = NULL;
    return map;
}

char **go_map(int size)
{
    char **map;
    int count = 1;

    map = map_memory(size);
    map[0] = my_memset(map[0], '*', (size * 2) + 1);
    for (count = 1; count < size + 1; count++) {
        map[count] = my_memset(map[count], ' ', (size * 2) + 1);
        map[count][0] = '*';
        map[count][size * 2] = '*';
    }
    map[size + 1] = my_memset(map[size + 1], '*', (size * 2) + 1);
    return map;
}

char ** go_match(int size, char **map)
{
    int x_axis = size;
    int y_axis = 1;
    int count = 0;

    for (count = 0; y_axis <= size; count++){
        x_axis = (size - count);
        while (x_axis < (size + count + 1)) {
            map[y_axis][x_axis] = '|';
            x_axis++;
        }
        y_axis++;
    }
    return map;
}
