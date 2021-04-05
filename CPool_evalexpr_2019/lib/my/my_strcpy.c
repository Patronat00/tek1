/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** task01
*/

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    for (;src[a] != '\0';a++) {
        dest[a] = src[a];
    }
    dest[a] = '\n';
    return (dest);
}
