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

int minimum_number(int a, int b, int c)
{
    if (a <= b && a <= c)
        return (a);
    if (b <= a && b <= c)
        return (b);
    if (c <= a && c <= b)
        return (c);
}
int solve_map(int **tab_tab, int i, int j, int *bigger)
{
    int x;
    int y;

    x = 1;
    y = 1;

    while (x < i + 1) {
        while (y < j + 1) {
            if ((y <= bigger[2] && y > bigger[2] - bigger[0])
                && (x <= bigger[1] && x > bigger[1] - bigger[0]))
                write(1, "x", 1);
            else if (tab_tab[x][y] == 0)
                write(1, "o", 1);
            else
                write(1, ".", 1);
            y++;
        }
        write(1, "\n", 1);
        x++;
        y = 1;
    }
    //free(bigger);
    //free (tab_tab);
}

int	*bigger_number(int **tab_tab, int i, int j)
{
	int x;
	int y;
	int *bigger;

	x = 0;
	y = 0;
	bigger = malloc(sizeof(int) * 6 - 1);
	bigger[0] = tab_tab[x][y];
	while (x < i + 1) {
		while (y < j + 1) {
			if (tab_tab[x][y] > bigger[0]) {
				bigger[0] = tab_tab[x][y];
				bigger[1] = x;
				bigger[2] = y;
			}
			y++;
		}
		x++;
		y = 1;
	}
    //solve_map(tab_tab, i, j, bigger_number(tab_tab, i, j));
    return (bigger);
}

int **the_square(char *buffer, int **tab_tab)
{
    int a = 0;
    int x = 0;
    int y = 0;
    int i = 0;
    int j = 0;

    for (int i = 0; i != my_getnbr(buffer) - 1; i++) {
        for (int j = 0; j != my_strlen(buffer); j++) {
            if (i == 0 || j == 0)
                continue;
            if (tab_tab[i][j] == 0)
                continue;
            else
                tab_tab[i][j] = 1 + minimum_number(tab_tab[i][j - 1],
                                        tab_tab[i - 1][j],
                                        tab_tab[i - 1][j - 1]);
        }
    }
    for (int i = 0; i != my_getnbr(buffer) - 1; i++) {
        for (int j = 0; j != my_strlen(buffer); j++)
            if(tab_tab[i][j] > a) {
                a = tab_tab[i][j];
                x = i;
                y = j;
            }
        my_put_nbr(tab_tab[i][j]);
        while (i < a || j < a) {
            tab_tab[x][y] = -1;
            x--;
            y--;
            j++;
            i++;
        }
        for (int i = 0; i != my_getnbr(buffer) - 1; i++) {
            for (int j = 0; j != my_strlen(buffer); j++) {
                my_put_nbr(tab_tab[i][j]);
            }
            my_putchar('\n');
        }
//        }
       // bigger_number(tab_tab, i, j);
        return (tab_tab);
    }
    free(tab_tab);
}

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
    tab_tab = the_square(buffer, tab_tab);
    my_putchar('\n');
    //free (tab_tab);
    //free(buffer);
    return (0);
}

    int main(int ac, char **av)
    {
        int fd = 0;
        int size = 0;
        char *buffer;
        int i = 1;

        if(ac != 2)
            return 84;
        struct stat size_fd;
        stat(av[1], &size_fd);
        buffer = malloc(sizeof(char) * (size_fd.st_size + 1));
        fd = open(av[1], O_RDONLY);
        if (fd < 0)
            return (84);
        size = stat(av[1], &size_fd);
        read(fd, buffer, size_fd.st_size);
        convert(buffer);
        //free(buffer);
        close(fd);
        return (0);
    }
