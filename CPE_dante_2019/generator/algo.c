/*
** EPITECH PROJECT, 2020
** algo.c
** File description:
** algo for perfect maze
*/

#include <stdlib.h>
#include "generator.h"

void perfect(t_dante *dante, char **maze)
{
    int a;
    int b;
    int random;

    a = 0;
    random = 0;
    while(a < dante->weight)
    {
        b = 0;
        dante->forward = 0;
        dante->right = 0;
        while(b < dante->lenght)
        {
            if (a == 0)
                maze[a][b] = '0';
            swap_forward_and_right(maze, a, b, dante);
            one_side(maze, a, b, dante);
            if(dante->forward == 1 && dante->right == 1)
                two_sides(maze, a, b, random);
            b += 2;
        }
        a += 2;
    }
}
