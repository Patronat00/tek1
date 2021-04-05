/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** my_strlowcase
*/

// min to maj = -32

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    return str;
}
