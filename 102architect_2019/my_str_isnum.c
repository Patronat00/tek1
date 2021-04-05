/*
** EPITECH PROJECT, 2019
** 102architect
** File description:
** isnum reforge
*/

#include <stdlib.h>

int my_str_isnum(char *str)
{
    int i = 0;
    
    while (str[i] != '\0') {
        if (str[i] > '9' || str[i] < '0')
            return (84);
        i++;
    }
    return(0);
}
