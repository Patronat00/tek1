/*
** EPITECH PROJECT, 2019
** CPool_Day_06
** File description:
** my_strcapitalize
*/

int i = 0;

static int verif_c(char str)
{
    if (str >= ' ' && str <= '/' || str >= ':' && str <= '@')
        return 0;
    else if (str >= '[' && str <= '`' || str >= '{' && str <= '~')
        return 0;
    else
        return 1;
}

char *my_strcapitalize(char *str)
{
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
    for (; str[i]; i++) {
        if ((str[i + 1] >= 'A' && str[i +1] <= 'Z') && verif_c(str[i] == 1))
            str[i + 1] = str[i + 1] + 32;
        if ((str[i + 1] >= 'a' && str[i + 1] <= 'z') && verif_c(str[i]) == 0)
            str[i + 1] = str[i + 1] - 32;
    }
    return str;
}
