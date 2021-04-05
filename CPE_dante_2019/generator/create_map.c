/*
** EPITECH PROJECT, 2020
** create_map.c
** File description:
** create the map for dante
*/

#include <stdlib.h>
#include "generator.h"

void create_map(t_dante *dante, int lenght, int weight)
{
    dante->forward = 0;
    dante->right = 0;
    dante->lenght = lenght + (lenght + 1);
    dante->weight = weight + (weight + 1);
}
