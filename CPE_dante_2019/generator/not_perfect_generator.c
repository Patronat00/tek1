/*
** EPITECH PROJECT, 2020
** not_perfect_generator.c
** File description:
** algo for not perfect generator
*/

#include <stdlib.h>
#include "generator.h"

void not_perfect_generator (int lenght, int weight)
{
    char **maze;
    t_dante dante;

    create_map(&dante, lenght, weight);
    if ((maze = space_map(lenght, weight)) == NULL)
        return ;
    maze = create_init(maze, lenght, weight);
    perfect(&dante, maze);
    no_stars(maze, lenght, weight);
    change_map(maze, lenght, weight);
}
