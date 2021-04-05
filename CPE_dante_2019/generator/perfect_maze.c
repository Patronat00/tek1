/*
** EPITECH PROJECT, 2020
** perfect_maze.c
** File description:
** perfect maze generator
*/

#include <stdlib.h>
#include "generator.h"

void one_side(char **maze, int a, int b, t_dante *dante)
{
    if (a - 1 >= 0 && dante->forward == 1 && dante->right == 0)
        maze[a - 1][b] = '0';
    if (b - 1 >= 0 && dante->forward == 0 && dante->right == 1)
        maze[a][b - 1] = '0';
}
