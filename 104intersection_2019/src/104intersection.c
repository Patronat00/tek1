/*
** EPITECH PROJECT, 2019
** 104intersection.c
** File description:
** 140intertion
*/

#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"
#include "include/proto.h"

int calcul_sphere(struct intersection intersection, char **av)
{
    printf("Sphere of radius %.0f\n", intersection.square_radius);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n",
           intersection.a, intersection.b, intersection.c, intersection.vector_a, intersection.vector_b,
           intersection.vector_c);
    intersection.equation_a = pow(intersection.vector_a, 2) + pow(intersection.vector_b, 2)
        + pow(intersection.vector_c, 2);
    intersection.equation_b = ((intersection.a * intersection.vector_a) + (intersection.b * intersection.vector_b)
                               + (intersection.c * intersection.vector_c)) * 2;
    intersection.equation_c = (pow(intersection.a, 2) + pow(intersection.b, 2) + pow(intersection.c, 2))
        - pow(intersection.square_radius, 2);
    intersection.delta = pow(intersection.equation_b, 2) - (4 * intersection.equation_a * intersection.equation_c);
    if (intersection.delta < 0)
        delta_negative(intersection);
    else if (intersection.delta == 0)
        delta_null(intersection);
    else if (intersection.delta > 0)
        delta_positive(intersection);
    return 0;
}

int calcul_cylinder(struct intersection intersection, char **av)
{
    printf("Cylinder of radius %.0f\n", intersection.square_radius);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n",
           intersection.a, intersection.b, intersection.c, intersection.vector_a, intersection.vector_b,
           intersection.vector_c);
    intersection.equation_a = pow(intersection.vector_a, 2) + pow(intersection.vector_b, 2)
        + pow(intersection.vector_c, 2);
    intersection.equation_b = ((intersection.a * intersection.vector_a) + (intersection.b * intersection.vector_b)
                               + (intersection.c * intersection.vector_c)) * 2;
    intersection.equation_c =  pow(intersection.square_radius, 2) * (- 1);
    intersection.delta = pow(intersection.equation_b, 2) - (4 * intersection.equation_a * intersection.equation_c);
    if (intersection.delta < 0)
        delta_negative(intersection);
    else if (intersection.delta == 0)
        delta_null(intersection);
    else if (intersection.delta > 0)
        delta_positive(intersection);
    return (0);
}

int calcul_cone(struct intersection intersection , char **av)
{
    if (intersection.square_radius >= 90)
        exit(84);
    printf("Cone with a %.0f degree angle\n", intersection.square_radius);
    printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n",
           intersection.a, intersection.b, intersection.c, intersection.vector_a, intersection.vector_b,
           intersection.vector_c);
    intersection.equation_a = pow(intersection.vector_a, 2) +
        pow(intersection.vector_b, 2) +
        ((pow(intersection.vector_c, 2)) * intersection.tang_square * (-1));
    intersection.equation_b = ((intersection.a * intersection.vector_a) +
                               (intersection.b * intersection.vector_b)
                               + ((intersection.c * intersection.vector_c) * intersection.tang_square) * (-1)) * 2;
    intersection.equation_c = pow(intersection.a, 2) + pow(intersection.b, 2) +
        ((pow(intersection.c, 2)) * intersection.tang_square * (-1));
    intersection.delta = pow(intersection.equation_b, 2) - (4 * intersection.equation_a * intersection.equation_c);
    if (intersection.delta < 0)
        delta_null(intersection);
    else if (intersection.delta == 0)
        delta_null(intersection);
    else if (intersection.delta > 0)
        delta_positive(intersection);
    return 0;
}

int attribute_values(struct intersection intersection, char **av)
{
    intersection.a = atof(av[2]);
    intersection.b = atof(av[3]);
    intersection.c = atof(av[4]);
    intersection.vector_a = atof(av[5]);
    intersection.vector_b = atof(av[6]);
    intersection.vector_c = atof(av[7]);
    intersection.square_radius = atof(av[8]);
    if (intersection.square_radius < 0)
        exit (84);
    if (intersection.vector_a == 0 && intersection.vector_b == 0 && intersection.vector_c == 0)
        exit(84);
    intersection.radiant = intersection.square_radius * (M_PI / 180);
    intersection.tang_square = tan(intersection.radiant) * tan(intersection.radiant);
    which_calc(intersection, av);
    return (0);
}

int main(int ac, char **av)
{
    struct intersection intersection;

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            help();
    }
    if (ac != 9)
        return (84);
    for (int i = 1, j = 0; i != ac - 1; j++) {
        if (av[i][j] == '\0') {
            i++;
            j = 0;
        }
        if (av[i][j] < '0' || av[i][j] > '9')
            if (av[i][j] != '-')
                return (84);
    }
    attribute_values(intersection, av);
    return (0);
}