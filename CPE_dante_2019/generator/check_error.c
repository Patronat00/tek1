/*
** EPITECH PROJECT, 2020
** check_error.c
** File description:
** errors checking
*/

int check_dimensions(char *a, char *b)
{
    int n;

    n = 0;
    while (a[n] != '\0')
    {
        if (a[n] < '0' || a[n] > '9')
            return (-1);
        n++;
    }
    n = 0;
    while (b[n] != '\0')
    {
        if (b[n] < '0' || b[n] > '9')
            return (-1);
        n++;
    }
    return (0);
}
