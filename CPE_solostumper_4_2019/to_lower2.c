/*
** EPITECH PROJECT, 2020
** to_lower2.c
** File description:
** lower 2 for solo4
*/

int to_lower2 (char **av, int i)
{
    switch (av[1][i]) {
    case 'e' :
        av[1][i] = av[1][i] - 50;
        break;
    case 'a' :
        av[1][i] = av[1][i] - 45;
        break;
    case 'y' :
        av[1][i] = av[1][i] - 68;
        break;
    }
}
