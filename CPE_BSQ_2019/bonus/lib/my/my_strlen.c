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
    int nb = 0;
    int i = 0;
    int j = 0;
    int lenght = 1;
  
    for (; str[j] != '\n'; j++)
        lenght += 1;
    for (int i = lenght; str[i] != '\n'; i++)
        nb++;
    return (nb);
}
