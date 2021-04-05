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

void delta_null(struct intersection intersection)
{
    printf("1 intersection point:\n");
    intersection.x0 = (intersection.equation_b * (-1)) / (2 * intersection.equation_a);
    intersection.xt = intersection.a + intersection.vector_a * intersection.x0;
    intersection.yt = intersection.b + intersection.vector_b * intersection.x0;
    intersection.zt = intersection.c + intersection.vector_c * intersection.x0;
    printf("(%.3f, %.3f, %.3f)\n", intersection.xt, intersection.yt, intersection.zt);
}
