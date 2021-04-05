/*
** EPITECH PROJECT, 2020
** two_sides.c
** File description:
** when there are two sides
*/

#include <stdlib.h>
#include "generator.h"

void two_sides(char **maze, int a, int b, int random)
{
    random = rand()%2;
    if (b - 1 >= 0 && random == 0)
        maze[a][b - 1] = '0';
    else if (a - 1 >= 0 && random == 1)
        maze[a - 1][b] = '0';
}
