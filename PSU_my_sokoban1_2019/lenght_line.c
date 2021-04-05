/*
** EPITECH PROJECT, 2019
** distance.c
** File description:
** calcul numbers of characters
*/

int lenght_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n')
        i = i + 1;
    return i;
}
