/*
** EPITECH PROJECT, 2020
** not_perfect_maze.c
** File description:
** generate not perfect maze
*/

#include <stdlib.h>
#include "generator.h"

void no_stars(char **maze, int lenght, int weight)
{
    int a;
    int b;
    int x;
    int y;

    a = 0;
    b = (lenght * weight) / 2;
    x = 0;
    y = 0;
    while (a < b)
    {
        x = rand()%lenght;
        y = rand()%weight;
        if (maze[y][x] == '1')
            maze[y][x] = '0';
        a++;
    }
}
