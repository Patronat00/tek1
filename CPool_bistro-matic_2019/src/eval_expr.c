/*
** EPITECH PROJECT, 2019
** eval_expr.c
** File description:
** evalexpr
*/

#include <stdio.h>

int priority(char *str, char *str2)
{
    int nb = 0;
    int nb2 = 0;
    int res = 0;
    int i = 0;
    char calc = sign(str);

    while (str[i] != '\0') {
        for (;str[i] != '\0'; i++)
            if (str[i] == str[0]) {
                str = str + 1;
                calcl(str, i, res);
            }
        for (; str[i] != '\0'; i++)
            if (str[i] == str2[4] || str2[5] || str2[6]) {
                res = calcl(nb, nb2, str);
            }
        for (; str[i] != '\0';i++)
            if (str[i] == str[2] || str[3]) {
                res = res + calcl(nb, nb2, str);
                return (res);
            }
    }
}

char *eval_expr(char *str, char *str2, char *expr, int size)
{
    char res;
    res = priority(str, str2);
    return (res);
}
