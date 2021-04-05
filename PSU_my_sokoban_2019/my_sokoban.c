/*
** EPITECH PROJECT, 2019
** test_open.c
** File description:
** test_open
*/

#include "include/proto.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>
#include <ncurses.h>


int display_ncurse(char * buffer)
{
    int key = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while(1) {
        clear();
        printw(buffer);
        key = getch();

        if (key == KEY_RIGHT) {
            movements_to_right(buffer);
        }
        else if (key == KEY_LEFT) {
            movements_to_left(buffer);
        }
        else if (key == KEY_DOWN) {
            movements_to_down(buffer);
        }
        else if (key == KEY_UP) {
            movements_to_up(buffer);
        }
        refresh();
        if (key == 32)
            break;
    }
    endwin();
    return (0);
}

int main(int ac, char **av) {
    int fd = 0;
    char *buffer = NULL;

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        manual();
        return (0);
    }
    struct stat size_fd;
    stat(av[1], &size_fd);
    buffer = malloc(sizeof(char) * (size_fd.st_size + 1));
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
        return 84;
    check_map(buffer);
    read(fd, buffer, size_fd.st_size);
    display_ncurse(buffer);
    close(fd);
    return (0);
}
