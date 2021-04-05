/*
** EPITECH PROJECT, 2020
** util.h
** File description:
**  minishell
*/

#ifndef UTIL_H_
# define UTIL_H_

# include "minishell.h"

char *scan_line(const int file);
int count_char(char *str, char c);
char *rev_substr(char *str, char c, int index);
char *trimstr(char *str, char c);
bool equalstr(char *a, char *b);
char **splitstr(char *str, char delimiter);
int str_length(char *str);
bool start_withstr(char *str, char *charset);
char *tab_start_withstr(char **tab, char *charset);
int tab_length(char **tab);
char *strdupl(char *str);
void free_tab(char **tab);
char *concatstr(char *a, char *b, bool free_a);
bool safe_freesub(char **ptr, bool free_sub);
bool safe_free(void *ptr);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
#endif
