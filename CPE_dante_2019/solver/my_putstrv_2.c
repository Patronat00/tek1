/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** efficace putstr
*/
#include <unistd.h>

int my_strlen(char const *str, int a);

char *my_putstr (char const *str)
{
    write(1, str, my_strlen(str, 0));
}
