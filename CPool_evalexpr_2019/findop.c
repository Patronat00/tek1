/*
** EPITECH PROJECT, 2019
** findop
** File description:
** findop
*/

int findop(char const *str, char calc)
{
    int nb = 0;
    int i = 0;

    for (; str[i] != '\0'; i = i + 1) {
        if (str[i] == calc)
            nb += 1;
    }
}
