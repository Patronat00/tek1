/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_show_word_array
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_putstr(char const *str);
void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
