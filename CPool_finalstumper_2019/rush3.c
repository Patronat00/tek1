/*
** EPITECH PROJECT, 2019
** test.c
** File description:
** testfinalstumper
*/

#include "include/rush3.h"

int rush1_1(char *str, int x, int y)
{
    if (str[0] == 'o') {
        my_putstr("[rush1-1] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putchar('\n');
    }
    return (0);
}

int rush1_2(char *str, int x, int y)
{
    if (str[0] == '*' || str[0] == '/') {
        my_putstr("[rush1-2] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putchar('\n');
    }
    return (0);
}

int rush1_3(char *str, int x, int y)
{
    int last_char = 0;
    int len = my_strlen(str);
    
    for (int i = 0; str[i] != '\n'; i++)
        last_char++;
    if (str[0] == 'A' && str[len - 2] == 'C' && str[last_char - 1] == 'A') {
        my_putstr("[rush1-3] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putchar('\n');
    }
}

int rush1_4(char *str, int x, int y)
{
    int last_char = 0;
    int len = my_strlen(str);
    
    for (int i = 0; str[i] != '\n'; i++)
        last_char++;
    if (str[0] == 'A' && str[len - 2] == 'C' && str[last_char - 1] == 'C') {
        my_putstr("[rush1-4] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putchar('\n');
    }
}

int rush1_5(char *str, int x, int y)
{
    int len = my_strlen(str);

    if (str[0] == 'A' && str[len - 2] == 'A') {
        my_putstr("[rush1-5] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putchar('\n');
    }
}
