/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strupcase
*/

// min to maj = -32

char *my_strupcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    return str;
}
