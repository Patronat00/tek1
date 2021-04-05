/*
** EPITECH PROJECT, 2019
** fs_understand_return_of_read.c
** File description:
** return of read
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "include/my.h"
#include <stdio.h>

int convert(char *buffer)
{
    int x = 0;
    int i = 0;
    int y = 0;
    int **tab_tab;

    my_put_nbr(my_getnbr(buffer));
    tab_tab = malloc(sizeof(int *) * (my_getnbr(buffer) + 1));
    for (int count = 0; count != my_getnbr(buffer); count ++) {
        tab_tab[count] = malloc(sizeof(int) * (my_strlen(buffer)));
        x++;
    }
    x = 0;
    for (; buffer[i] != '\0' && x < my_getnbr(buffer); y++) {
        if (buffer[i] == '.')
            tab_tab[x][y] = 1;
        if (buffer[i] == 'o')
            tab_tab[x][y] = 0;
        if (buffer[i] == '\n') {
            x++;
            y = 0;
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int fd = 0;
    int size = 0;
    char *buffer;
    int i = 1;

    if(ac != 2)
        return (84);
    struct stat size_fd;
    stat(av[1], &size_fd);
    buffer = malloc(sizeof(char) * (size_fd.st_size + 1));
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return 84;
    size = stat(av[1], &size_fd);
    read(fd, buffer, size_fd.st_size);
    for(int j; buffer[j] != '\n'; j++)
        i++;
    while (buffer[i] != '\0') {
        my_putchar(buffer[i]);
        i++;
    }
    close(fd);
    return (0);
}
