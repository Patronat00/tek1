/*
** EPITECH PROJECT, 2020
** allocate_map.c
** File description:
** allocate memory for the maze
*/

#include <stdlib.h>
#include "generator.h"

char **space_map(int lenght, int weight)
{
    int a;
    int lenght_max;
    int weight_max;
    char **maze;

    a = 0;
    if (lenght == 0 || weight == 0)
        return NULL;
    weight_max = weight + (weight + 1);
    lenght_max = lenght + (lenght + 1);
    if ((maze = malloc(sizeof(char *) * (weight_max + 1)\
)) == NULL)
        return NULL;
    while (a < weight_max)
    {
        if ((maze[a] = malloc(sizeof(char) * (lenght_max\
 + 1))) == NULL)
            return NULL;
        a++;
    }
    maze[a] = NULL;
    return (maze);
}
