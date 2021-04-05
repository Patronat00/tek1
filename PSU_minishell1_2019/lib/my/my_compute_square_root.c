/*
** EPITECH PROJECT, 2019
** CPool_Day05_2019
** File description:
** my_compute_square_root
*/

#include <stdio.h>

static int my_square_range(int nb, int r)
{
    while (nb > 100) {
        nb /= 100;
        r *= 10;
    }
    return r;
}

int my_compute_square_root(int nb)
{
    int r = 1;

    r = my_square_range(nb, r);

    while (nb != (r * r)) {
        r += 1;
        if (r * r > nb)
            return 0;
    }
    return r;
}
