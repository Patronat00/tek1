/*
** EPITECH PROJECT, 2019
** bistro-matic
** File description:
** bistro's main
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromatic.h"

void  my_putstr(char const *);
int   my_strlen(char const *);

char *get_expr(int size, char *expr)
{
    if (size <= 0)
        exit(84);
    if (expr == 0)
        exit(84);
    if (read(0, expr, size) != size)
        exit(84);
    expr[size] = 0;
    return (expr);
}

int main (int ac, char **av)
{
    int size = 0;
    char *expr;

    if (ac != 4) {
        my_putstr("Usage: ");
        my_putstr(av[0]);
        my_putstr(" base ops\"()+_*/%\" exp_len\n");
        return (84);
    }
    if (my_strlen(av[1]) < 2)
        return (84);
    if (my_strlen(av[2]) != 7) {
        my_putstr("error_synth");
        return (84);
    }
    size = my_getnbr(av[3]);
    expr = malloc(size + 1);
    expr = get_expr(size, expr);
    my_putstr(eval_expr(av[1], av[2], expr, size));
    return (0);
}
