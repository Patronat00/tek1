/*
** EPITECH PROJECT, 2019
** wich_calc.c
** File description:
** choose the type of calcul 
*/

#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/struct.h"
#include "../include/proto.h"

void which_calc(struct intersection intersection, char **av)
{
    if (atof(av[1]) == 1)
        calcul_sphere(intersection, av);
    else if (atof(av[1]) == 2)
        calcul_cylinder(intersection, av);
    else if (atof(av[1]) == 3)
        calcul_cone(intersection, av);
    else
        exit(84);
}
