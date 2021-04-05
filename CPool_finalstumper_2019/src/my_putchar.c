/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** 02/10/19 22:23
*/

#include <unistd.h>

void my_putchar(char c)
{
    write (1, &c, 1);
}
