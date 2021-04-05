/*
** EPITECH PROJECT, 2019
** homer.c
** File description:
** loop to display key matrix
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void manual(void);

int main(int ac, char **av) {

    if (ac == 2) {
        if (av[1][0] == '-' && av[1][1] == 'h') {
            manual();
            return 0;
        }
        return 84;
    }
    if (ac < 3)
        return 84;
    if (av[3][0] == '0') {
        printf("Key matrix:\n");
        for (int i = 0; av[2][i] != '\0'; i++) {
            //si i est compris entre 5 et 9 alors matrix 3x3. Si i < 9, alors ajouter des 0 pour compléter la matrix 3x3
            // si i compris entre 2 et 4 alors matrix 2x2, alors ajouter des 0 pour compléter la matrix 2x2
            printf("%d\t", av[2][i]);
        }
        printf("\n");
        printf("\n");

        for (int i = 0; av[1][i] != '\0'; i++) {
            //si i est compris entre 5 et 9 alors matrix 3x3. Si i < 9, alors ajouter des 0 pour compléter la matrix 3x3
            // si i compris entre 2 et 4 alors matrix 2x2, alors ajouter des 0 pour compléter la matrix 2x2
            printf("%d\t", av[1][i]);
        }
    }
    printf("\n");
    printf("\n");
    printf("Encrypted message:\n");
    return 0;
}
/*Encryption:
- square root for size of matrix
- matrix K contains values
- M' contains M * K and is the encrypted matrix

Decryption:
- key -> matrix K
- inverted K
- encrypted message to M'
- decrypted M = M' * invert K
*/