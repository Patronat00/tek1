/*
** EPITECH PROJECT, 2020
** dante
** File description:
** create_map
*/

#include "solve.h"

char **conv(char *buf, int ymax)
{
    char **map = malloc(sizeof(*map) * ymax + 1);
    int x = mal_n(buf, 0);
    int i = 0;

    for (int y = 0; y < ymax; y++) map[y] = malloc(sizeof(map) * x);
    for (int y = 0; map[y] != NULL; y++) {
        for (int x = 0; buf[i] != '\n'; x++) {
            if (buf[0] != '*') return NULL;
            map[y][x] = buf[i];
            i++;
        }
        i++;
    }
    return map;
}

char **put_maze(char *maze, solve_t *sol)
{
    struct stat st;
    int g = stat(maze, &st);
    char buf[st.st_size];
    char **map;
    int fd = 0;

    if ((fd = open(maze, O_RDONLY)) < 0) return NULL;
    if ((fd = read(fd, buf, st.st_size)) < 0) return NULL;
    sol->ymax = mal_n(buf, 1);
    sol->xmax = mal_n(buf, 0);
    if ((map = conv(buf, sol->ymax)) == NULL) return NULL;
    return map;
}
