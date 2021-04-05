/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_strlen
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}
