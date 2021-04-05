/*
** EPITECH PROJECT, 2020
** the main function
** File description:
** main.c
*/

#include "my.h"

void bombyx_formula(bombyx_t *bombyx)
{
    bombyx->xi_p_1 = (bombyx->k * bombyx->xi) * ((1000 - bombyx->xi) / 1000);
}

int first_method(bombyx_t *bombyx)
{
    int pos_i = 2;
    bombyx->x = bombyx->n;
    bombyx->xi = bombyx->x;

    printf("1 %.2f\n", bombyx->n);
    for (int i = 0; i != 99; i++, pos_i++) {
        bombyx_formula(bombyx);
        printf("%d ", pos_i);
        printf("%.2f\n", bombyx->xi_p_1);
        bombyx->xi = bombyx->xi_p_1;
    }
}

int arguments(bombyx_t *bombyx, char **av)
{
    bombyx->n = atof(av[1]);
    bombyx->k = atof(av[2]);
    bombyx->i0 = atoi(av[2]);
//    bombyx->i1 = atoi(av[3]);

    if (bombyx->n < 0)
        return (84);
    if (bombyx->k < 1 || bombyx->k > 4)
        return (84);
    /*  if (bombyx->i0 < 0 || bombyx->i0 > bombyx->i1)
        return (84);
    if (bombyx->i1 < 0 || bombyx->i1 < bombyx->i0)
    return (84);*/
}

int check_args(int ac, char **av)
{
    for (int i = 1, j = 0; i != ac - 1; j++) {
        if (av[i][j] == '\0') {
            i++;
            j = 0;
        }
        if (av[i][j] < '0' || av[i][j] > '9')
            if (av[i][j] != '-')
                return (84);
    }
}
int main(int ac, char **av)
{
    bombyx_t *bombyx = malloc(sizeof(bombyx_t));

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        description();
    if (check_args(ac, av) == 84)
        return (84);
    if (ac == 3) {
        arguments(bombyx, av);
        first_method(bombyx);
    }
    //  else if (ac == 4)
    //  second_method(bombyx);
    else
        return (84);
    return (0);
}
