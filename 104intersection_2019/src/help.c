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
    printf("USAGE\n    ./104intersection opt xp yp zp xv yv zv p\n\n");
    printf("DESCRIPTION\n    opt             surface option: 1 for a sphere, 2 for a cylinder, 3 for a cone\n");
    printf("    (xp, yp, zp)    coordinates of a point by which the light ray passes through");
    printf("    (xv, yv, zv)    coordinates of a vector parallel to the light ray\n");
    printf("    p               parameter: radius of the sphere, radius of the cylinder, or\n");
    printf("                    angle formed by the cone and the Z-axis\n");
    exit(0);
}
