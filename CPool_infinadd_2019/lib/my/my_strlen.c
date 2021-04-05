/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** 
*/

int my_strlen(char const *str)
{
    int n_char = 0;
    while (*str != '\0') {
        n_char++;
        str++;
    }
    return (n_char);
}
