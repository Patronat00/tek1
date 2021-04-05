/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_getnbr
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

int my_getnbr(char const *str)
{
    long int nb = 0;
    int neg = 1;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '-')
            neg *= -1;
        if ((str[i] < '0' || str[i] > '9') && nb > 0)
            return (nb);
        if (str[i] >= '0' && str[i] <='9')
            nb = (nb * 10) + (str[i] - '0');
        if (nb > 2147483648 && neg == -1 || nb > 2147483647 && neg == 1)
            return 0;
    }
    return ((int)nb * neg);
}

int my_getread(char *str)
{
    int count = 0;
    int result = 0;

    if (str[0] < '0' || str[0] > '9')
        return -1;
    for (count = 0; str[count] != '\n'; count++) {
        if (str[count] < '0' || str[count] > '9')
            return -1;
        result *= 10;
        result += str[count] - '0';
    }
    return result;
}
