/*
** EPITECH PROJECT, 2020
** dante
** File description:
** solve.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

typedef struct solve {
    char **maze;
    int **visited;
    int xmax;
    int ymax;
}solve_t;

enum pedtrude {empty, fill, end, crumble};

int mal_n(char *buffer, int choice);
char **conv(char *buf, int ymax);
char **put_maze(char *maze, solve_t *sol);
void my_putstr(char *str);
