/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** task1_Dday08
*/

#include <stdlib.h>

int my_strlen(char const *str);
char *my_strdup(char const *src)
{
    char *str;
    int i;
    
    i = 0;
    str = malloc(sizeof (char) * (my_strlen(src) + 1));
    
    while (src[i] != '\0')
    {
        str[i] = src[i];
        i++;
    }
    
    str[i] = src[i];
    return (str);
}
