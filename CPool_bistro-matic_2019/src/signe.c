/*
** EPITECH PROJECT, 2019
** signe
** File description:
** signe
*/

#include <stdio.h>

char sign(char const *str)
{
    long long int i = 0;
    char calc;

    while (str[i] != '\0') {
        if (str[i] == str[2])
            calc = '+';
        if (str[i] == str[3])
            calc = '-';
        if (str[i] == str[4])
            calc = '*';
        if (str[i] == str[5])
            calc = '/';
        if (str[i] == str[6])
            calc = '%';
        i++;
    }
    return (calc);
}

int calcl(int nb, int nb2, char *str, char *str2)
{
    char calc = sign(str2);
    long long int res = 0;

    if (calc == str[2]) {
        res = nb + nb2;
        my_putchar('a');
    }
    if (calc == str[3]) {
        res = nb - nb2;
        my_putchar('b');
    }
    if (calc == str[4]) {
        res = nb * nb2;
        my_putchar('c');
    }
    if (calc == str[5]) {
        res = nb / nb2;
        my_putchar('d');
    }
    if (calc == str[6]) {
        res = nb % nb2;
        my_putchar('e');
    }
    return (res);
}
