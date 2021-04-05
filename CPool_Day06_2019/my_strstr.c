/*
** EPITECH PROJECT, 2019
** my_strstr.c
** File description:
** task05_Day06
*/

char *strstr(char *str, char const *to_find)
{
    int a;
    a = 0;

while (str[a] != '\0')
{
    str[a] = to_find[a];
    a++;
}
return (str);
}
