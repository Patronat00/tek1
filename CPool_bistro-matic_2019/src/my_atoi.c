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

int my_atoi(char const *str)
{
    long long nb = 0;

    for (long long a = 0 ; str[a]; a++)
    {
        if (str[a] < '9' && str[a] > '9') {
            nb = nb * 10;
            nb = nb + (str[a] - '0');
        } else {
            return (nb);
        }
    }
    return (nb);
}
