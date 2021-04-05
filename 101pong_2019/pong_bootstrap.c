/*
** EPITECH PROJECT, 2019
** bootstrap_pong.c
** File description:
** pong
*/

#include "include/vectors.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <complex.h>

char *usage(char **av)
{
    printf("USAGE\n");
    printf("    ./101pong x0 y0 z0 x1 y1 z1 n\n");
    printf("DESCRIPTION\n");
    printf("    x0 ball abscissa at time t - 1\n");
    printf("    y0 ball ordinate at time t - 1\n");
    printf("    z0 ball altitude at time t - 1\n");
    printf("    x1 ball abscissa at time t\n");
    printf("    y1 ball abscissa at time t\n");
    printf("    z1 ball altitude at time t\n");
    printf("    time shift (greater than or equal to zero, integer\n");
}

void output(struct vectors a_point, double angle, char **av)
{
    int time = atoi(av[7]);

    my_putstr("The velocity vector of the ball is:\n");
    printf("(%.2f, %.2f, %.2f)\n", a_point.Xv, a_point.Yv, a_point.Zv);
    printf("At time t + %d, ball coordinates will be:\n", time);
    printf("(%.2f, %.2f, %.2f)\n", a_point.Xt, a_point.Yt, a_point.Zt);
    if (angle > 0 && angle < 90) {
        my_putstr("The incidence angle is:\n");
        printf("%.2f degrees\n", angle);
    }
    else
        my_putstr("The ball won't reach the paddle.\n");
}

int main(int ac, char **av)
{
    double result_normeV;
    double angle;
    struct vectors a_point;

    if (av[1][0] == '-' && av[1][1] == 'h') {
        usage(av);
        return (0);
    }
    if (ac != 8)
        return (84);

    a_point.Xv = atof(av[4]) - atof(av[1]);
    a_point.Yv = atof(av[5]) - atof(av[2]);
    a_point.Zv = atof(av[6]) - atof(av[3]);
    if (a_point.Zv == -3)
        a_point.Zv = a_point.Zv * (-1);
    a_point.normeV = (a_point.Xv * a_point.Xv) + (a_point.Yv * a_point.Yv) + (a_point.Zv * a_point.Zv);
    result_normeV = sqrtf(a_point.normeV);
    a_point.Z_divide_normeV = a_point.Zv / result_normeV;
    angle = asinf(a_point.Z_divide_normeV);
    angle = angle * (180 / M_PI);
    a_point.Xt  = a_point.Xv * (atof(av[7]) + 1) +(atof(av[1]));
    a_point.Yt = a_point.Yv * (atof(av[7]) + 1) + (atof(av[2]));
    a_point.Zt = a_point.Zv * (my_getnbr(av[7]) + 1) + (atof(av[3]));
    output(a_point, angle, av);
    return (0);
}
