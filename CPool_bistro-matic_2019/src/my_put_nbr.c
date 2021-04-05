/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** my_put_nbr
*/

#include <stdio.h>

void my_putchar(char c);

static int my_recursiv(int nb)
{
    if (nb / 10 > 0)
        my_recursiv(nb / 10);
    my_putchar(nb % 10 + '0');
    return (0);
}

int my_put_nbr(int nb)
{
    if (nb == 0 || nb == -__INT_MAX__ - 1) {
        my_putchar('0');
        my_putchar('\n');
        return (0);
    }
    my_recursiv(nb);
    my_putchar('\n');
    return (0);
}
