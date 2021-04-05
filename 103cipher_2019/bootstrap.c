/*
** EPITECH PROJECT, 2019
** bootstrap.c
** File description:
** exercice 1
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(int ac, char **av) {
    char *str = av[1];

    printf("Key matrix:\n");
    for (int i = 0; av[2][i] != '\0'; i++) {
       // printf("i = %d\n", i);
     //  if (i >= 5 && i <= 9) {
            printf("%d    %d    %d\n", av[2][0], av[2][1], av[2][2]);
            printf("%d   %d    %d\n", av[2][3], av[2][4], av[2][5]);
            printf("%d    0      0\n", av[2][6]);
          //  printf("i = %d\n", i);
      //  }
    }
//    printf("i = %d\n", i);

    return 0;
}
