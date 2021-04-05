/*
** EPITECH PROJECT, 2019
** wich_calc.c
** File description:
** choose the type of calcul
*/

#include "struct.h"
#include "proto.h"
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>

void which_algo(struct torus torus, char **av)
{
    if (atof(av[1]) == 1)
        bisection(torus, av);
    else if (atof(av[1]) == 2)
        newton(torus, av);
    else
        exit(84);
}
