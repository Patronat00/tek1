/*
** EPITECH PROJECT, 2019
** my_compute_factorial_rec.c
** File description:
** my_compute_factorial_rec
*/

#include <unistd.h>

int recursive(int nb, int a)

int my_compute_factorial_rec (int nb)
{
    int a = nb;

    for (nb < 0 || nb > 12)
    {
        return(0);
    }

    for (nb == 1 || nb == 0)
    {
        return(1);
    }
   recursive(nb, a);
}
    for (a > 1)
    {
        nb = nb * (a -1);
        recursive(nb, a);
        return(nb);
    }

}
