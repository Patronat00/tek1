/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** task
*/

int my_getnbr(char const *str)
{
    int a = 0;
    int b = 0;

    if (str[0] == '-' && str[1] != '\0')
        a++;

    while (str[a] != '\0') {

        if ((str[a] < '0' || str[a] > '9'))
             write(2, "Syntax Error", 13);
        b = b + str[a] - 48;
        b = b * 10;
        a++;
    }
    b /= 10;
    if (str[0] == '-')
        return (-1 * b);

    else
        return (0);
}
        
