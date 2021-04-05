/*
** EPITECH PROJECT, 2019
** 102 architect
** File description:
** matrixing
*/

#include <stdio.h>

void manual(void)
{
    printf("USAGE\n    ./102architect x y transfo1 arg11 [arg12] [transfo2 %s",
           "arg12 [arg22]] ...\n\n");
    printf("DESCRIPTION\n    x   abscissa of the original point\n%s%s",
           "    y   ordinate of the original point\n",
           "    transfo arg1 [arg2]\n");
    printf("    -t i j  translation along vector (i, j)\n%s%s%s%s",
           "    -z m n  scaling by factors m (x-axis) and n (y-axis)\n",
           "    -r d    rotation centered in 0 by a d degree angle\n",
           "    -s d    reflection over the axis passing through 0 with an ",
           "inclination angle of d degrees\n");
}
