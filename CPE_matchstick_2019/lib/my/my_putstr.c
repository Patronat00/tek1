/*
** EPITECH PROJECT, 2019
** CPool_Day04_2019
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putchar(char c);

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (0);
}