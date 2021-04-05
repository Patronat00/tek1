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
    int size = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            size++;
    }
    return (size);
}
