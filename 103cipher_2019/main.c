/*
** EPITECH PROJECT, 2019
** 103cipher
** File description:
** 103cipher's main
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char **key_find(int **key, char **av, int nbr_square)
{
    int key_size = 0, rows_nbr = 0;

    for (int i = 0; av[2][i]; i++)
        key_size++;
    rows_nbr = nbr_square / key_size;
    key = malloc(sizeof (int *) * rows_nbr);
    for (int i = 0; i <= rows_nbr; i++)
        key[i] = malloc(sizeof (int) * nbr_square);
    return (key);
}

int main (int ac, char **av)
{
    int string_len = 0, matrix_size = 0, nbr_square = 0;
    int **matrix_1, key;

    for (int i = 0; av[1][i]; i++)
        string_len++;
    for (int size = 0; matrix_size < string_len; size++)
        matrix_size = size * size;
    nbr_square = sqrt(matrix_size);
    matrix_1 = malloc(sizeof (int *) * nbr_square);
    for (int i = 0; i != nbr_square; i++)
        matrix_1[i] = malloc(sizeof (int) * nbr_square);
    for (int i = 0, j = 0; i != string_len; i++) {
        if (i / nbr_square == nbr_square)
            j++;
        matrix_1[j][i] = av[1][i];
    }
    key = key_find(key, av, nbr_square);
    free(matrix_1);
    free(key);
    return (0);
}
