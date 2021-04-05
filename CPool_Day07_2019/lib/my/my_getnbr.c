/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** task
*/

int my_getnbr(char const *str)
{
    int a;
    a = 0;

    while (str[a] == '0')
        a++;

    while (str[a] != '\0') {
        a++;
        my_putchar(str[a]);
    }

    return (0);
}

