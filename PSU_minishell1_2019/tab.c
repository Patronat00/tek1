/*
** EPITECH PROJECT, 2020
** tan.c
** File description:
**  minishell
*/

#include "util.h"
#include <stdlib.h>

int	tab_length(char **tab)
{
    int	i;

    i = 0;
    while (tab && tab[i] && ++i);
    return (i);
}

char	*tab_start_withstr(char **tab, char *charset)
{
    while (tab && *tab)
        if (start_withstr(*tab++, charset))
            return (*(tab - 1));
    return (NULL);
}

void	free_tab(char **tab)
{
    int	i;

    i = -1;
    while (tab && tab[++i])
        free(tab[i]);
    if (tab)
        free(tab);
}