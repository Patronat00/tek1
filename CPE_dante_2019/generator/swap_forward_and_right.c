/*
** EPITECH PROJECT, 2020
** swap_forward_and_right.c
** File description:
** swap up and right for the map
*/

#include <stdlib.h>
#include "generator.h"

void swap_forward_and_right(char **maze, int a, int b, t\
_dante *dante)
{
    if (a - 1 >= 0 && maze[a - 1][b] == '1')
        dante->forward = 1;
    if (b - 1 >= 0 && maze[a][b - 1] == '1')
        dante->right = 1;
}
