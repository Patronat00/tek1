/*
** EPITECH PROJECT, 2019
** 105torus.c
** File description:
** 105torus
*/

#include "struct.h"
#include "proto.h"
#include <math.h>
#include <complex.h>
#include <stdlib.h>
#include <stdio.h>

int newton(struct torus torus, char **av) {
    torus.xn = 0.5;
    torus.equation_xn = (torus.a4 * powf(torus.xn, 4)) + (torus.a3 * powf(torus.xn, 3)) + (torus.a2 * powf(torus.n, 2)) +
            (torus.a1 * torus.xn) + torus.a0;
    torus.equation_deriv = (4 * torus.a4 * powf(torus.xn, 3) + (3 * torus.a3 * powf(torus.xn, 2)) +
                            (2 * torus.a2 * powf(torus.xn, 2)) + torus.a1);
    torus.equation_xn1 =
            (torus.a4 * powf(torus.xn1, 4)) + (torus.a3 * powf(torus.xn1, 3)) + (torus.a2 * powf(torus.xn1, 2)) +
            (torus.a1 * torus.xn1) + torus.a0;
    while (torus.equation_xn1 > powf(10, torus.n * (-1))) {
        if (torus.equation_deriv == 0)
            return 84;
        else
        torus.xn1 = torus.xn - (torus.xn / torus.equation_deriv);
            printf("x = %.*f\n", torus.n, torus.xn1);
    }
    return 0;
}

int bisection(struct torus torus, char **av)
{
    torus.a = 0;
    torus.b = 1;
    //torus.c = (torus.a + torus.b) / 2;
    torus.equation_c = (torus.a4 * powf(torus.c, 4)) + (torus.a3 * powf(torus.c, 3)) + (torus.a2 * powf(torus.c, 2)) + (torus.a1 * torus.c) + torus.a0;
    torus.equation_a = (torus.a4 * powf(torus.a, 4)) + (torus.a3 * powf(torus.a, 3)) + (torus.a2 * powf(torus.a, 2)) + (torus.a1 * torus.a) + torus.a0;
    while (fabsf(torus.equation_c) > powf(10, -(torus.n))) {
       //torus.c = (torus.a + torus.b) / 2;
        if ((torus.equation_a * torus.equation_c) < 0) {
            torus.b = torus.c;
            torus.c = (torus.a + torus.c) / 2;
            printf("x = %.*f\n", torus.n, torus.c);
        }
        else {
            torus.c = (torus.c + torus.b) / 2;
            printf("x = %.*f\n", torus.n, torus.c);
        }
    }
    return 0;
}

int attribute_values(struct torus torus, char **av)
{
    torus.algorithm = atof(av[1]);
    torus.a4 = atof(av[2]);
    torus.a3 = atof(av[3]);
    torus.a2 = atof(av[4]);
    torus.a1 = atof(av[5]);
    torus.a0 = atof(av[6]);
    torus.n = atof(av[7]);
    if (torus.a0 == 0 && torus.a1 == 0 && torus.a2 == 0 && torus.a3 == 0 && torus.a4 == 0)
        exit(84);
    which_algo(torus, av);
}

int main(int ac, char **av)
{
    struct torus torus;

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h')
            help();
    }
    if (ac != 8)
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
    attribute_values(torus, av);
}
