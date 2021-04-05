/*
** EPITECH PROJECT, 2020
** dante
** File description:
** solver/main.c
*/

#include "solve.h"

void alloc_visit(solve_t *sol)
{
    sol->visited = malloc(sizeof(int *) * sol->ymax);
    for (int i = 0; i < sol->xmax; i++)
        sol->visited[i] = malloc(sizeof(int) * sol->xmax);
    for (int y = 0; y < sol->ymax; y++) {
        for (int x = 0; x < sol->xmax; x++) {
            if (sol->maze[y][x] == NULL)
                sol->visited[y][x] = fill;
            if (sol->maze[y][x] == '*')
                sol->visited[y][x] = empty;
            if (sol->maze[y][x] == 'X')
                sol->visited[y][x] = fill;
        }
    }
}

int solve(solve_t *need, int x, int y)
{
    int **oui = need->visited;
    int *act = &oui[y][x];

    if (x == need->xmax && y == need->ymax) return 1;
    if (*act == empty) {
        *act = crumble;
        if (x + 1 <= need->xmax && solve(need, x + 1, y))
            return 1;
        if (y + 1 <= need->ymax && solve(need, x, y + 1))
            return 1;
        if (x - 1 >= 0 && solve(need, x - 1, y))
            return 1;
        if (y - 1 >= 0 && solve(need, x, y - 1))
            return 1;
        *act = empty;
    }
    return 0;
}

void trail(solve_t *sol)
{
    for (int y = 0; y < sol->ymax; y++) {
        for (int x = 0; x < sol->xmax; x++) {
            if (sol->visited[y][x] == crumble)
                sol->maze[y][x] = 'o';
        }
    }
}

int main(int ac, char **av)
{
    char **maze;
    solve_t *sol = malloc(sizeof(*sol));

    if (ac != 2) return 84;
    if ((sol->maze = put_maze(av[1], sol)) == NULL) return 84;
    alloc_visit(sol);
    if (solve(sol, 0, 0) == 0)
        return 84;
    else
        trail(sol);
    for (int i = 0; sol->maze[i] != NULL; i++) {
        my_putstr(sol->maze[i]);
        if (sol->maze[i + 1] != NULL)
        write(1, "\n", 1);
    }
    free(sol);
}
