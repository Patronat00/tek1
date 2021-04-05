/*
** EPITECH PROJECT, 2019
** rush3.h
** File description:
** 26/10/19
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int rush1_1(char *str, int x, int y);
int rush1_2(char *str, int x, int y);
int rush1_3(char *str, int x, int y);
int rush1_4(char *str, int x, int y);
int rush1_5(char *str, int x, int y);
int rush3to5_special_case(char *str, int x, int y);
void find_x_y(char *str);

