/*
** EPITECH PROJECT, 2020
** perfect_generator.c
** File description:
** generate perfect maze
*/

#include <stdlib.h>
#include "generator.h"

void perfect_generator(int lenght, int weight)
{
    t_dante dante;
    char **maze;

    create_map(&dante, lenght, weight);
    if ((maze = space_map(lenght, weight)) == NULL)
        return ;
    maze = create_init(maze, lenght, weight);
    perfect(&dante, maze);
    change_map(maze, lenght, weight);
}
