/*
** EPITECH PROJECT, 2019
** my_revstr.c
** File description:
** task01
*/

/* int my_strlen(char const *src) */
/* { */
/*     int tabl = 0; */
/*     while (src[tabl] != '\0'){ */
/*         tabl = tabl + 1; */
/*     } */
/*     return (tabl); */
/* } */

char *my_revstr(char *str)
{
    int longeur = 0;
    int i = 0;
    char *temp;
    
    while (str[i] != '\0') {
        longeur = longeur + 1;
        i = i + 1;
    }
    i = 0;
    while (i < longeur) {
        temp = *(str + i);
        *(str + i) = *(str + longeur - 1);
        *(str + longeur - 1) = temp;
        longeur--;
        i++;
    }
    return (str);
}
