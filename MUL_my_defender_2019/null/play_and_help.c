/*
** EPITECH PROJECT, 2020
** play_and_help.c
** File description:
** play and help cases
*/

#include "defender.h"
#include "include/my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int open_file(int ac, char **av, int *choice)
{
    int fd = 0;
    int size = 0;
    char *buffer;
    
    struct stat size_fd;
    stat(av[1], &size_fd);
    buffer = malloc(sizeof(char) * (size_fd.st_size + 1));
    fd = open("map.txt", O_RDONLY);
    if (fd < 0)
        return (84);
    size = stat("map.txt", &size_fd);
    read(fd, buffer, size_fd.st_size);
}
