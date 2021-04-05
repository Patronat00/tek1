/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#ifndef SHOW_H
#define SHOW_H

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE_PATH_TEXTURE 3
#define GRASS '0'
#define ROAD '1'

#define CONV_CHAR_TO_INT(x) (x - '0')

#define GRASS_INT CONV_CHAR_TO_INT(GRASS)
#define ROAD_INT CONV_CHAR_TO_INT(ROAD)

#define X_MAX HEIGTH / SIZE_HEIGTH_PIXE

#define NB_CHAR_IN_FILE \
(HEIGTH / SIZE_HEIGTH_PIXE) * (LENGTH / SIZE_WIDTH_PIXE)

#define SIZE_WIDTH_PIXE 120
#define SIZE_HEIGTH_PIXE 96

#define HEIGTH 1920
#define LENGTH 1080

char *cube[3];

typedef struct win_view_s {
    sfRenderWindow *window;
    sfVector2f V_view;
    float S_view;
} win_view_t;

typedef struct game_s {
    sfTexture *t_case;
    sfSprite **s_case;
    sfIntRect *r_case;
    sfVector2f *v_case;
} game_t;

typedef struct grid_size_s {
    float gridesizef;
    unsigned gridsizeu;
    int map_size;
    sfVector2f size;
} grid_size_t;

typedef struct select_s {
    sfVector2i mouse_ps;
    sfVector2i mouse_pw;
    sfVector2f mouse_pv;
    sfVector2u mouse_pg;
} select_t;

typedef struct case_sel_s {
    sfSprite **map;
    sfSprite ***select;
    int xmax;
    int ymax;
    sfVector2f grid_selector;
} case_sel_t;

typedef struct random {
    sfSprite *sprite;
    sfTexture *select;
    int type_map;
} map_test;

typedef struct time_s {
    sfClock *timer;
    sfTime temp;
    float second;
    int nb;
} timee_t;

typedef struct map_s {
    win_view_t *show;
    grid_size_t *grid;
    select_t *m;
    case_sel_t *cell;
    char *maps;
    int tab_int[(HEIGTH / SIZE_HEIGTH_PIXE + 1) *
        (LENGTH / SIZE_WIDTH_PIXE + 1)];
} map_t;

typedef struct int_ints_s {
    int zero;
    int one;
    int two;
    int tree;
} int_ints_t;

//-------------------struct_menu--------------------------------------->>

typedef struct object {
    sfTexture *textobj;
    sfIntRect obj_rect;
    sfSprite *sprite_obj;
    sfVector2f vect_obj;
} object_t;

typedef struct menu {
    object_t *play;
    object_t *help;
    object_t *quit;
    object_t *backg;
} menu_t;

typedef struct sprites {
    sfVector2f sprite_position_play;
    sfVector2f sprite_position_help;
    sfVector2f sprite_position_exit;
} sprites_t;

//--------------------struct_mob--------------------------------------->>

typedef struct tower {
    object_t *base;
    int damage;
    int hp;
    struct tower_t *next;
} tower_t;

typedef struct enemy {
    object_t *obj;
    int hp;
    int damage;
    struct enemy *next;
} enemy_t;

typedef struct obj_s {
    enemy_t *enemy;
    tower_t *tower;
    int gold;
    int hp_base;
}obj_t;

typedef struct systeme_s {
    map_t *screen;
    timee_t *anim_time;
    obj_t *enemy;
    menu_t *menu;
} systeme_t;

//---------------------set.c------------------------------------------->>
timee_t *spawn_time(timee_t *time);
void set_pos_map(float gridesizef, case_sel_t *cell);
select_t *set_selector(select_t *m, grid_size_t *gr, win_view_t *sh);
int *set_visual_g(grid_size_t *grid, win_view_t *sh);
case_sel_t *set_select(case_sel_t *cell, grid_size_t *grid, select_t *m);

//---------------------init.c------------------------------------------>>
struct sfSprite **map_sprite(int x, int y, char *file);
win_view_t *init_win_view(int x, int y, int frame, char *name);
grid_size_t *init_grid(int map_size, float gridsizef, int size_x, int size_y);
case_sel_t *init_sprite(char *sel, grid_size_t *grid, char *file);
map_t *init_map(int_ints_t ps, char *file);

int game(systeme_t *sys);

int mal_n(char *buffer, int choice);

void two_d_to_one_d(char *str, int *tab_int);
char **conv(char *buf, int ymax);
char *put_map(char *str);

void free_game (map_t *map);
int destroy_obj(object_t *obj);
int destroy_mob(enemy_t *mob);

void add_mob(enemy_t **index, map_t *map_handle);
int list_count(enemy_t *index);

void put_tower_in_way(tower_t **tower, sfEventType type,
        sfRenderWindow *window);
void add_tower(tower_t **index, sfVector2f vector);

int check_live_mob(enemy_t *mob);
int check_mob_on_way(enemy_t *mob);

int menu(systeme_t *sys);
void set_button (menu_t *menu);
object_t *texture(char *image, int width, int height);
sprites_t *sprite_positions(menu_t *menu);

void move_rect(sfIntRect *rect, int offset, int max_value);
void anim_sprite(enemy_t *list, timee_t *anim_time);

int initialize (char *file);

void handle_movement(enemy_t *enemys, int *tab, map_t *map);
void restart_mob(enemy_t *mob, systeme_t *sys);
systeme_t *handle_selector(systeme_t *sys);

#endif