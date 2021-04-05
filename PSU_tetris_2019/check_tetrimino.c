/*
** EPITECH PROJECT, 2020
** check_tetrimino.c
** File description:
**
*/

#include "my.h"

int check_errors(int fd, tetris_t *tetris, int read_fd)
{
    if (fd == -1)
        return (84);
    if (tetris->buff == NULL)
        return (84);
    if (read_fd == -1)
        return (84);
}

int check_tetrimino(char *filepath, tetris_t *tetris)
{
    int fd = open(filepath, O_RDONLY);
    struct stat size_file;
    stat(filepath, &size_file);
    tetris->size = size_file.st_size;
    tetris->buff = malloc(sizeof(char) * tetris->size);
    int read_fd = read(fd, tetris->buff, tetris->size);

    if (check_errors(fd, tetris, read_fd) == 84)
        return (84);
    tetris->buff[tetris->size] = '\0';
}

int transfo_buff(char *filepath, tetris_t *tetris)
{
    tetris->arr = malloc(sizeof(char *) * tetris->size);

    printf("\n");
    if (check_tetrimino(filepath, tetris) == 84)
        return (84);
    for (int x = 0; tetris->buff[x] != '\0'; x++) {
        tetris->arr[x] = malloc(sizeof(char) * tetris->size);
        for (int y = 0; tetris->buff[y] != '\n'; y++) {
            tetris->arr[x][y] = tetris->buff[x];
            printf("%c", tetris->arr[x][y]);
        }
        printf("\n");
    }
}

int main(int ac, char **av)
{
    tetris_t *tetris = malloc(sizeof(tetris));

    if(av[1][0] == '-' && av[1][1] == '-' && av[1][2] == 'h' && av[1][3] == 'e'\
       && av[1][4] == 'l' && av[1][5] == 'p')
        help();
    if(ac != 2)
        return (84);
    transfo_buff(av[1], tetris);
    return (0);
}
