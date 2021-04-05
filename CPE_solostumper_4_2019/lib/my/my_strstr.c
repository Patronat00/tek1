/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strstr
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == to_find[j])
            j++;
        if (!to_find[j])
            return str + i - --j;
    }
    return NULL;
}
