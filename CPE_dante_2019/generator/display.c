/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** display
*/

#include <stdio.h>

void display(char **maze, int lenght, int weight)
{
    int a;
    int b;
    int undisplay;

    a = 0;
    undisplay = 0;
    while(a < weight)
    {
        b = 0;
        while(b < lenght)
        {
            if(a == weight - 1 && b == lenght - 1 && maze[a][b - 1] == '1')
            {
                printf("*");
                undisplay = 1;
            }
            if(maze[a][b] == '0')
                printf("*");
            if(maze[a][b] == '1' && undisplay != 1)
                printf("X");
            b++;
        }
        printf("\n");
        a++;
    }
}

void change_map(char **maze, int lenght, int weight)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while(a < weight - 1)
        a++;
    while(b < lenght - 1)
        b++;
    if(maze[a][b - 1] == '1' && maze[a - 1][b] == '1')
        maze[a][b - 1] = '0';
    display(maze, lenght, weight);
}
