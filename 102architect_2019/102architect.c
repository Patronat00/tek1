/*
** EPITECH PROJECT, 2019
** 102architect.c
** File description:
** 102architect
*/

#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/struct.h"

#define Check(value) ((value) < 0 && (value) > -0.00001 || (value) == -0 ? ((value) + 42) - 42 : (value))

void manual(void);
int my_str_isnum(char *str);

int translation_matrix(struct architect matrix, char **av)
{
    matrix.x0 = atof(av[1]);
    matrix.y0 = atof(av[2]);
    matrix.i = atof(av[4]);
    matrix.j = atof(av[5]);
    matrix.x1 = matrix.i + matrix.x0;
    matrix.y1 = matrix.y0 + matrix.j;
    printf("Translation along vector (%.0f, %.0f)\n", matrix.i, matrix.j);
    printf("1.00    0.00    %.2f\n", Check(matrix.i));
    printf("0.00    1.00    %.2f\n", Check(matrix.j));
    printf("0.00    0.00    1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", Check(matrix.x0), Check(matrix.y0), Check(matrix.x1), Check(matrix.y1));
}

int reflection_axis(struct architect matrix, char **av)
{
    matrix.teta = atof(av[4]);
    matrix.x0 = atof(av[1]);
    matrix.y0 = atof(av[2]);
    matrix.radiant = matrix.teta * (M_PI / 180);
    matrix.x1 = (matrix.x0 * (cos(2 * matrix.radiant)) + ((matrix.y0 * sin(2 * matrix.radiant))));
    matrix.y1 = (matrix.x0 * (sin(2 * matrix.radiant)) + ((matrix.y0 * (cos(2 * matrix.radiant) *(-1)))));
    printf("Reflection over an axis with an inclination angle of %.0f degrees\n", matrix.teta);
    matrix.a = cos(2 * matrix.radiant);
    matrix.b = sin(2 * matrix.radiant);
    matrix.c = sin(2 * matrix.radiant);
    matrix.d = cos(2 * matrix.radiant) * (-1);
    printf("%.2f    %.2f    0.00\n", Check(matrix.a), Check(matrix.b));
    printf("%.2f    %.2f    0.00\n", Check(matrix.c), Check(matrix.d));
    printf("0.00    0.00    1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", Check(matrix.x0), Check(matrix.y0), Check(matrix.x1), Check(matrix.y1));
}

int rotation_matrix(struct architect matrix, char **av)
{
    matrix.teta = atof(av[4]);
    matrix.x0 = atof(av[1]);
    matrix.y0 = atof(av[2]);
    matrix.radiant = matrix.teta * (M_PI / 180);
    matrix.x1 = (matrix.x0 * cos(matrix.radiant)) + ((matrix.y0 * (-sin(matrix.radiant))));
    matrix.y1 = (matrix.x0 * sin(matrix.radiant)) + ((matrix.y0 * cos(matrix.radiant)));
    matrix.a = cos(matrix.radiant);
    matrix.b = sin(matrix.radiant * (-1));
    matrix.c = sin(matrix.radiant);
    matrix.d = cos(matrix.radiant);
    printf("Rotation by a %.0f degree angle\n", matrix.teta);
    printf("%.2f    %.2f    0.00\n", Check(matrix.a), Check(matrix.b));
    printf("%.2f    %.2f    0.00\n", Check(matrix.c), Check(matrix.d));
    printf("0.00    0.00    1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", Check(matrix.x0), Check(matrix.y0), Check(matrix.x1), Check(matrix.y1));
}

int scaling_by_factors(struct architect matrix, char **av)
{
    matrix.m = atof(av[4]);
    matrix.n = atof(av[5]);
    matrix.x0 = atof(av[1]);
    matrix.y0 = atof(av[2]);
    matrix.x1 = matrix.m * matrix.x0;
    matrix.y1 = matrix.n * matrix.y0;
    printf("Scaling by factors %.0f and %.0f\n", matrix.m, matrix.n);
    printf("%.2f   0.00    0.00\n", Check(matrix.m));
    printf("0.00    %.2f    0.00\n", Check(matrix.n));
    printf("0.00    0.00    1.00\n");
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", Check(matrix.x0), Check(matrix.y0), Check(matrix.x1), Check(matrix.y1));
}

int main (int ac, char **av)
{
    struct architect matrix;

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            manual();
            return (0);
        }
        return (84);
    }
    if(ac < 3)
        return 84;
    if (av[3][0] == '-' && av[3][1] == 'z') {
        if (ac != 6)
            return (84);
        my_str_isnum(av[1]);
        my_str_isnum(av[2]);
        my_str_isnum(av[4]);
        my_str_isnum(av[5]);
        scaling_by_factors(matrix, av);
        return (0);
    }
    if (av[3][0] == '-' && av[3][1] == 'r') {
        if (ac != 5)
            return (84);
        my_str_isnum(av[1]);
        my_str_isnum(av[2]);
        my_str_isnum(av[4]);
        rotation_matrix(matrix, av);
        return (0);
    }
    if (av[3][0] == '-' && av[3][1] == 's') {
        if (ac != 5)
            return (84);
        my_str_isnum(av[1]);
        my_str_isnum(av[2]);
        my_str_isnum(av[4]);
        reflection_axis(matrix, av);
        return (0);
    }
    if (av[3][0] == '-' && av[3][1] == 't') {
        if (ac != 6)
            return (84);
        my_str_isnum(av[1]);
        my_str_isnum(av[2]);
        my_str_isnum(av[4]);
        my_str_isnum(av[5]);
        translation_matrix(matrix, av);
        return (0);
    }
}
