/* EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** task01_Day06
*/

#include <string.h>

char my_strcpy(char *dest, char const *src)
{
    int i;
    i = 0;

    while (src[i] != '\0')
    {
         dest[i] = src[i];
         i++;
    }
    my_putchar(dest);
}
