/*
** EPITECH PROJECT, 2019
** eval_expr.c
** File description:
** evalexpr
*/

#include "include/my.h"
#include <stdio.h>

int calcl(int nb, int nb2, char const *str);

int eval_expr(char const *str)
{
    int nb = 0;
    int nb2 = 0; 
    int res = 0;
    int i = 0;
    char calc = sign(str);

    for (;str[i] != '\0'; i++) {
        if (str[i] == '(')
            for (; str[i] != ')'; i++)
                str = str + i;
        for (; str[i] != sign(str); i++)
            nb = (nb * 10) + (str[i] - '0');
        i++;
        for (; str[i] != '\0'; i++)
            nb2  = (nb2 * 10) +  (str[i] - '0');
        res = calcl(nb,nb2,str);
        return (res);
    }
}

int main(int ac , char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        return (0);
    }
    return (84);
}
