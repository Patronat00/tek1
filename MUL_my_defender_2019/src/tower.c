/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tower.c
*/

#include "show.h"

void put_tower_in_way(tower_t **tower, sfEventType type, sfRenderWindow *window)
{
    static int mode = 0;

    if (type == sfEvtMouseButtonPressed) {
        add_tower(tower, (sfVector2f) {(float)
        sfMouse_getPositionRenderWindow(window).x,
        (float)sfMouse_getPositionRenderWindow(window).y
        - (SIZE_WIDTH_PIXE / 2)});
    }
}

void add_tower(tower_t **index, sfVector2f vector)
{
    tower_t *tower = malloc(sizeof(*tower));

    tower->base = malloc(sizeof(object_t));
    tower->base->sprite_obj = sfSprite_create();
    tower->base->textobj = sfTexture_createFromFile("tower.png", NULL);
    sfSprite_setTexture(tower->base->sprite_obj, tower->base->textobj, sfTrue);
    tower->damage = 1;
    sfSprite_setPosition(tower->base->sprite_obj, vector);
    tower->next = *index;
    *index = tower;
}