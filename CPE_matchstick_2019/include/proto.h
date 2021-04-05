/*
** EPITECH PROJECT, 2020
** proto.h
** File description:
** fonctions prototypes
*/

#include "../lib/my/my.h"

#ifndef PROTO_H_
#define MY_H_

typedef struct matchstick
{
    int del_match;
    int del_line;
    int mem_match;
} t_matchstick;

char **go_map(int size);
char **go_match(int size, char **map);
char **memory_map(int size);
void display(char **map);
void map_free(char **map, int size);
int game(char **map, int size, int mem);
int lose(char **map);
char **player_play(char **map, int size, int mem);
char **ai_play(char **map, int size, int mem);
int player_info(int *res);
int good_line(int line, int size);
int good_match(int match, int mem, int cancel_match);
void good_match_2(void);
char **remove_match(int match, int line, char **map);
int count_match(int line, char **map);
int good_line_ai(int line, int size);
int good_match_ai(int matches, int mem, int cancel_match);
int safe(int size);

#endif
