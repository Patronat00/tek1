/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** task02
*/

int my_putstr(char const *str)
{
    int tabl = 0;

    while (str[tabl] != '\0'){
        my_putchar(str[tabl]);
        tabl = tabl + 1;
    }
    return (0);
}
