/*
** EPITECH PROJECT, 2019
** 104intersection
** File description:
** man_help
*/

#include <stdio.h>
#include <stdlib.h>

void help(void)
{
    printf("USAGE\n    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
    printf("DESCRIPTION\n    opt             method option:\n \t\t\t1 for the bisection method\n");
    printf("     \t\t\t2 for the Newton's method\n");
    printf("     \t\t\t3 for the secant method\n");
    printf("    a[0-4]\t    coefficients of the equation\n");
    printf("    n               precision (the application of the polynominal to the solution should\n\t\t    "
           "be smaller than 10^-n)\n");
    exit(0);
}
