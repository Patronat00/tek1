/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** map_conv.c
*/

#include "show.h"

void two_d_to_one_d(char *str, int *tab_int)
{
    int f = 0;

    for (int i = 0; str[i] != '\0'; i++, f++) {
        if (str[i] == '\n') {
            f--;
            continue;
        }
        tab_int[f] = str[i] - '0';
    }
    tab_int[f] = -1;
}

char *my_getline(char *str, int size_file)
{
    int fd = open(str, O_RDONLY);
    char *buff = malloc(sizeof(char) * (size_file + 1));
    int count = 0;

    fd = read(fd, buff, size_file);
    if (!str || fd < 0)
        return NULL;
    buff[size_file] = '\0';
    return (buff);
}

char *put_map(char *str)
{
    struct stat st;
    int stats = stat(str, &st);
    char *file = my_getline(str, st.st_size);

    return file;
}
