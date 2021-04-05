/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** task03_Day06
*/

int my_revstr (char *str)
{
    int i = 0;
    int j = i--;

    while (str[i] != '\0')
    {
        i++;
    }
    return (j);
}
