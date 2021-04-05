/*
** EPITECH PROJECT, 2019
** signe
** File description:
** signe
*/

#include <stdio.h>

char sign(char const *str)
{
    int i = 0;
    char calc;

    while (str[i] != '\0') {
        if (str[i] == '+')
            calc = '+';
        if (str[i] == '-')
            calc = '-';
        if (str[i] == '*')
            calc = '*';
        if (str[i] == '/')
            calc = '/';
        if (str[i] == '%')
            calc = '%';
        i++;
    }
    return (calc);
}

int calcl(int nb, int nb2, char const *str)
{
    char calc = sign(str);
    int res = 0;

    if (calc == '+')
        res = nb + nb2;
    if (calc == '-')
        res = nb - nb2;
    if (calc == '*')
        res = nb * nb2;
    if (calc == '/')
        res = nb / nb2;
    if (calc == '%')
        res = nb % nb2;
    return (res);
}
