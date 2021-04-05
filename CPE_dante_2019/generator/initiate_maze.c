/*
** EPITECH PROJECT, 2020
** initiate_maze.c
** File description:
** initiate the maze
*/

#include <stdlib.h>
#include "generator.h"

char **create_init(char **maze, int lenght, int weight)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while (a < weight + (weight - 1))
    {
        b = 0;
        while(b < lenght + (lenght - 1))
        {
        if (b % 2 == 0 && a % 2 == 0)
            maze[a][b] = '0';
        else if (b % 2 != 0 && a % 2 == 0)
            maze[a][b] = '1';
        if (a % 2 != 0)
            maze[a][b] = '1';
        b++;
    }
    maze[a][b] = '\0';
    a++;
    }
    return (maze);
}
