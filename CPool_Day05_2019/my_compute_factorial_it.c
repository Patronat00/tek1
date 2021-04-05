/*
** EPITECH PROJECT, 2019
** my_compute_factorial_it.c
** File description:
** task01_Day05
*/

int my_compute_factorial_it (int nb)

{
    int a = nb;

    for (nb < 0 || nb > 12)
    {
        return(0);
    }

    while (a > 1)
    {
        nb = nb * (a - 1);
        a--;
    return(nb);
    }

    for (nb == 1 || nb == 0)
    {
        return(1);
    }
}
