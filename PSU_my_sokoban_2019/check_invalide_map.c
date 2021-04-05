/*
** EPITECH PROJECT, 2019
** check_invalide_map.c
** File description:
** check 
*/

#include "include/check_invalide_map.h"

int my_putstr(char const *str);

int check_map(char *buffer)
{
    int a;

    while (buffer[a] != '\0') {
        if (mapCheck(buffer[a])) {
            a = a + 1;
        }
        else
            return 84;
    }
    if (a != 0) {
        my_putstr("The map is not correct");
        return (84);
    }
}
