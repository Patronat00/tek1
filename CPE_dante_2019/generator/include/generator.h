/*
** EPITECH PROJECT, 2020
** generator.h
** File description:
** generator.h
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_

typedef struct t_dante
{
    int forward;
    int right;
    int weight;
    int lenght;
} t_dante;

int check_dimensions(char *a, char *b);
int my_strcmp(char const *s1, char const *s2);
void display(char **maze, int lenght, int weight);
void change_map(char **maze, int lenght, int weight);
char **space_map(int lenght, int weight);
char **create_init(char **maze, int lenght, int weight);
void create_map(t_dante *dante, int lenght, int weight);
int main (int ac, char **av);
void not_perfect_generator (int lenght, int weight);
void no_stars(char **maze, int lenght, int weight);
void one_side(char **maze, int a, int b, t_dante *dante);
void two_sides(char **maze, int a, int b, int random);
void swap_forward_and_right(char **maze, int a, int b, t_dante *dante);
void perfect_generator(int lenght, int weight);
char **create_init(char **maze, int lenght, int weight);
void perfect(t_dante *dante, char **maze);

#endif
