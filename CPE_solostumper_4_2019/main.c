/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** solo 4
*/

#include <unistd.h>
#include "include/proto.h"

int to_lower (char **av, int i)
{
    switch (av[1][i]) {
    case 'o' :
        av[1][i] = av[1][i] - 63;
        break;
    case 'i' :
        av[1][i] = av[1][i] - 56;
        break;
    case 'u' :
        av[1][i] = av[1][i] - 67;
        break;
    default:
        to_lower2(av, i);
       }
    my_putchar(av[1][i]);
}

int to_upper2 (char **av, int i)
{
    switch (av[1][i]) {
    case 'e' :
         av[1][i] = av[1][i] - 50;
          my_putchar(av[1][i]);
          break;
    case 'a' :
         av[1][i] = av[1][i] - 45;
         my_putchar(av[1][i]);
         break;
    case 'y' :
        av[1][i] = av[1][i] - 68;
        my_putchar(av[1][i]);
        break;
    }
}

int to_upper (char **av, int i)
{
    switch (av[1][i]) {
    case 'o' :
        av[1][i] = av[1][i] - 63;
        my_putchar(av[1][i]);
        break;
    case 'i' :
        av[1][i] = av[1][i] - 56;
        my_putchar(av[1][i]);
        break;
    case 'u' :
        av[1][i] = av[1][i] - 67;
        my_putchar(av[1][i]);
        break;
    default:
        to_upper2(av, i);
     }
    av[1][i] = av[1][i] - 32;
    my_putchar(av[1][i]);
}

int print (int ac, char **av)
{
    int i = 0;

    while (av[1][i] != '\0') {
        if (av[1][i] >= 'A' && av[1][i] <= 'Z') {
            av[1][i] = av[1][i] + 32;
            to_lower(av, i);
            i++;
        }
       else if (av[1][i] >= 'a' && av[1][i] <= 'z') {
            to_upper(av, i);
            i++;
        }
       else {
           my_putchar(av[1][i]);
            i++;
        }
    }
}

int main (int ac, char **av)
{
    if (ac !=2) {
        write(2, "Usage: geekNameFormatter string\n", 33);
        return 84;
    }
    print(ac, av);
    my_putchar('\n');
}
