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
#include "../include/struct.h"
#include "../include/proto.h"

void delta_positive(struct intersection intersection)
{
    intersection.x1 = (intersection.equation_b * (- 1) + sqrt(intersection.delta)) / (2 * intersection.equation_a);
    intersection.x2 = (intersection.equation_b * (- 1) - sqrt(intersection.delta)) / (2 * intersection.equation_a);
    intersection.xt = intersection.a + intersection.vector_a * intersection.x1;
    intersection.yt = intersection.b + intersection.vector_b * intersection.x1;
    intersection.zt = intersection.c + intersection.vector_c * intersection.x1;
    intersection.xt1 = intersection.a + intersection.vector_a * intersection.x2;
    intersection.yt1 = intersection.b + intersection.vector_b * intersection.x2;
    intersection.zt1 = intersection.c + intersection.vector_c * intersection.x2;
    printf("2 intersection points:\n");
    printf("(%.3f, %.3f, %.3f)\n", intersection.xt, intersection.yt, intersection.zt);
    printf("(%.3f, %.3f, %.3f)\n", intersection.xt1, intersection.yt1, intersection.zt1);
}
