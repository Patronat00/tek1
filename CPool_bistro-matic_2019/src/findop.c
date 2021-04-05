/*
** EPITECH PROJECT, 2019
** findop
** File description:
** findop
*/

long long int findop(char const *str, char calc)
{
    long long int nb = 0;
    long long int i = 0;

    for (; str[i] != '\0'; i = i + 1) {
               if (str[i] == calc)
            nb += 1;
    }
}
