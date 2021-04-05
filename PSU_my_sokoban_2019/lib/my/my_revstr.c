/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_revstr
*/

static int my_strlen(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}

char *my_revstr(char *str)
{
    int max = my_strlen(str) - 1;
    int tmp;

    str[max + 1] = '\0';
    for (int i = 0; str[i] && i < max; i++) {
        tmp = str[i];
        str[i] = str[max];
        str[max] = tmp;
        max--;
    }
    return str;
}
