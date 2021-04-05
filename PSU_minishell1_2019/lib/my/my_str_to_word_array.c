/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_str_to_word_array
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static int is_alphanum(char const c)
{
    return !(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'z') &&
        !(c >= 'A' && c <= 'Z');
}

static int how_many_word(char const *str)
{
    int k = 0;

    for (int i = 0; str[i]; i++)
        if ((!is_alphanum(str[i]) && is_alphanum(str[i + 1])))
            k += 1;
    return k;
}

static int get_my_word_len(char const *str)
{
    int i = 0;

    for (; str && str[i] && is_alphanum(str[i]) == 0; i++);
    return i;
}

static void fill(char *tab, char const **str, int word_len)
{
    for (; **str && !is_alphanum(**str); *str += 1)
        *tab++ = **str;
    *tab = 0;
    for (; is_alphanum(**str) && **str; *str += 1);

}

char **my_str_to_word_array(char const *str)
{
    char **tab;
    int word_len = 0;
    int size = 0;
    int i = 0;
    if (str == 0)
        return 0;
    size = how_many_word(str);
    tab = malloc((size + 1) * sizeof(*tab));
    if (!tab)
        return NULL;
    for (; is_alphanum(*str); ++str);
    for (; i < size; i++) {
        word_len = get_my_word_len(str);
        tab[i] = malloc((word_len + 1) * sizeof(**tab));
        if (!tab[i])
            return NULL;
        fill(tab[i], &str, word_len);
    }
    tab[i] = 0;
    return tab;
}
