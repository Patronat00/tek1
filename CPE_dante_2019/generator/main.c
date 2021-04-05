/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main generator dante
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "generator.h"

int main (int ac, char **av)
{
    srand(getpid() * time(NULL));
    if (ac == 3)
    {
        if (check_dimensions(av[1], av[2]) == - 1)
            return -1;
        not_perfect_generator(atoi(av[1]), atoi(av[2]));
    }
    else if (ac == 4)
    {
        if (check_dimensions(av[1], av[2]) == - 1 || my_strcmp("parfait", av[3]) == 1)
            return -1;
        perfect_generator(atoi(av[1]), atoi(av[2]));
    }
    return 0;
}
