/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** task02_Day04
*/

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}
