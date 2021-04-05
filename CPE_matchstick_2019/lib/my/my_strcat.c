/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strcat
*/

#include "my.h"
#include <string.h>

//int my_strlen(char const *src);

char *my_strcat(char *dest, char const *src)
{
    unsigned int dest_lenght = my_strlen(dest);
    unsigned int i = 0;

    for (i = 0; src[i]; i++)
        dest[dest_lenght + i] = src[i];
    dest[dest_lenght + i] = 0;
    return dest;
}

char *my_strcat_read(char *dest, char src)
{
    int len = my_strlen(dest);

    dest[len] = src;
    dest[len + 1] = '\0';
    return dest;
}
