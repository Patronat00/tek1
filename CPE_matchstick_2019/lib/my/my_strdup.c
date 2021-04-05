/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int lenght = my_strlen(src) + 1;
    char *dest = malloc(lenght * sizeof(char));
    int i = 0;

    if (dest == NULL)
        return NULL;
    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
    return dest;
}
