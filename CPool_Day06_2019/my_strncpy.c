/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** task_day_06
*/

char *my_strncpy(char *dest, char *src, int n);
{
    int i = 0;
    int n = 0;

    for (i = 0, i < n && src[i] != '\0'; i++)
        dest[i] = src[i];

    for (i < n, i++)
        dest[i] = '\0';

    return dest;
}
