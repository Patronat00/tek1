/*
** EPITECH PROJECT, 2019
** finalstumper.c
** File description:
** rush3
*/

#include "include/rush3.h"

int rush3to5_special_case(char *str, int x, int y)
{
    if (str[0] == 'B' && x == 1 || y == 1) {
        my_putstr("[rush1-3] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putstr(" || [rush1-4] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putstr(" || [rush1-5] ");
        my_put_nbr(x);
        my_putchar(' ');
        my_put_nbr(y);
        my_putchar('\n');
    }
    return (0);
}

void find_x_y(char *str)
{
    int x = 0;
    int y = 0;

    while (str[x] != '\n')
        x++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            y++;
    }
    rush1_1(str, x, y);
    rush1_2(str, x, y);
    rush1_3(str, x, y);
    rush1_4(str, x, y);
    rush1_5(str, x, y);
    rush3to5_special_case(str, x, y);
}

int main()
{
    char buff[10000];
    int offset = 0;
    int len;

    while ((len = read(0, buff + offset, 10000 - offset)) > 0)
        offset = offset + len;
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    find_x_y(buff);
    return (0);
}
