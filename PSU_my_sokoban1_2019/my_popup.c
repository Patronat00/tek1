/*
** EPITECH PROJECT, 2019
** my_popup.c
** File description:
** my_popup
*/

#include <ncurses.h>
#include <stdlib.h>

int my_strlen(char const *str);

int main (int ac, char **av)
{
    WINDOW *boite;
    int lenght = my_strlen(av[1]);

    initscr();
    while(1) {
        clear();
        mvprintw(LINES/2, (COLS / 2) - (lenght /2), av[1]);
        refresh();
        if(getch() != 410)
            break;
        }
    endwin();
    return (0);
}
