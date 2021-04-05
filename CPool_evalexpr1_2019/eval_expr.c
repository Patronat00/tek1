/*
** EPITECH PROJECT, 2019
** eval_expr.c
** File description:
** eval_expr
*/

#include <stdio.h>

int eval_expr(char const *str)
{
    int a = 0;
    int i= 0;
    
    int chiffre = my_getnbr(str);
    
    //if (str[i] == '+') {
    
    /*     if (str[i] == '(') { */
    
    /*         while (str[i] != ')') { */
    /*             i++; */
    /*         a = i + i; */
    /*         my_put_nbr(a); */
    /*         } */
    /*     } */
    /* } */
    my_put_nbr(chiffre);
    printf("%s",str);
}


int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}
