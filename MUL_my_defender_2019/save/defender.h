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

//----------------------------utilitaire-----------------------------//
typedef struct object {
    sfTexture *textobj;
    sfIntRect obj_rect;
    sfSprite *sprite_obj;
} object_t;
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
    sfVector2f sprite_tower;
} sprites_t;
//-------------------------game-------------------------------------//
typedef struct basic {
    object_t *base;
    int gold;
    int hp_base;
} basic_t;

typedef struct tower {
    object_t *base;
    int damage;
    int hp;
} tower_t;

typedef struct enemy {
    object_t *enemy;
    int hp;
    int damage;
//    enemy *next;
} enemy_t;

typedef struct index {
    enemy_t *first;
    enemy_t *last;
} index_t;
