
/*
** EPITECH PROJECT, 2019
** infin_add.c
** File description:
** adding the infinite
*/

#include <stdlib.h>

char *conversion(char *str, int c)
{
    int a = 0;
    int b = 0;

    for (;a != c; c--) {
        if (str[c] > '9') {
            b = str[c] - '0';
            str[c] = b % 10 + '0';
            str[c - 1] = (str[c - 1] - '0') + 1 + '0';
        }
    }
    if (str[0] > '9') {
        a = str[0] - '0';
        str[0] = a % 10 + '0';
        my_putchar('1');
    }
    return(str);
}

char *adding(char *chara, char *chara2, char *str)
{
    int a = 0;
    int c = 0;
    int result = 0;

    for (;chara[c] || chara2[c]; c++) {
        result = chara[c] - '0' + chara2[c] - '0';
        str[c] = result + '0';
    }
    conversion(str, c);
    return (str);
}

char *fill_space(char *final, char *src)
{
    int len_final = my_strlen(final);
    int i = 0;
    int len3 = my_strlen(final) - my_strlen(src);
    char *str_fin = malloc(len_final);

    for (int k = 0; k < len_final; k++)
        str_fin[k] = '0';
    for (int k = 0; k < len_final; k++, i++) {
        while (k < len3)
            k++;
        str_fin[k] = src[i];
    }
    return (str_fin);
}

int infin_add(char *av, char *av2)
{
    int len = my_strlen(av);
    int len2 = my_strlen(av2);
    char *str = malloc(sizeof(char) * (len + len2) + 1);

    if (len > len2) {
        av2 = fill_space(av, av2);
    } else if (len < len2)
        av = fill_space(av2, av);
    adding(av, av2, str);
    return (str);
}
