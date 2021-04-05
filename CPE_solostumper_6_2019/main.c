/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** solo 4
*/

#include <unistd.h>
#include "include/proto.h"

int transf(char **av, int i)
{
    if (av[1][i - 1] == ' ' && av[1][i] >= 'a' && av[1][i] <= 'z')
        to_upper(av, i);
    else if (av[1][i- 1] == ' ' && av[1][i + 1] == ' ') {
        my_putchar(av[1][i]);
        my_putchar('.');
    }
    else (av[1][i - 1] == ' ' && av[1][i] >= 'A' && av[1][i] <= 'Z');
    my_putchar(av[1][i]);
}

int to_upper (char **av, int i)
{
    av[1][i] = av[1][i] - 32;
}

int print (int ac, char **av)
{
    int i = 1;

    while (av[1][i] != '\0') {
        if (av[1][0] >= 'a' && av[1][0] <= 'z') {
            av[1][0] = av[1][0] - 32;
            my_putchar(av[1][0]);
        }
        else if (av[1][i - 1] != ' ' && av[1][i] >= 'A' && av[1][i] <= 'Z') {
            av[1][i] = av[1][i] + 32;
            my_putchar(av[1][i]);
            i++;
        }
        else {
            transf(av, i);
            i++;
        }
    }
}

int main (int ac, char **av)
{
    if (ac !=2) {
        write(2, "Usage: USNameFormatter string\n", 31);
        return 84;
    }
    print(ac, av);
    my_putchar('\n');
}
