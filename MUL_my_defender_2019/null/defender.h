/*
** EPITECH PROJECT, 2020
** defender.h
** File description:
** structures for defender
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//----------------------------utilitaire-----------------------------//
typedef struct object {
    sfTexture *textobj;
    sfIntRect obj_rect;
    sfSprite *sprite_obj;
    sfVector2f vect_obj;
} object_t;

typedef struct map {
    int x;
    char **map;
    int y;
} map_t;
//----------------------------menu----------------------------------//
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
//-------------------------game-------------------------------------//
typedef struct tower {
    object_t *base;
    int damage;
    int hp;
} tower_t;

typedef struct enemy {
    object_t *obj;
    int hp;
    int damage;
    struct enemy *next;
} enemy_t;

typedef struct list_mobdad {
    enemy_t *first;
    enemy_t *last;
}list_mob_t;
/*
typedef struct index {
    enemy_t *first;
    enemy_t *last;
} index_t;
*/
typedef struct game {
    enemy_t mob;
    tower_t *tower;
    object_t *background;
    object_t *base;
    int gold;
    int hp_base;
}game_t;
