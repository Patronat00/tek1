/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_game.c
*/

#include "show.h"

object_t *texture(char *image, int width, int height)
{
    object_t *texture = malloc(sizeof(object_t));

    texture->sprite_obj = sfSprite_create();
    texture->textobj = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture (texture->sprite_obj, texture->textobj, sfTrue);
    if (width != 0 || height != 0) {
        texture->obj_rect.left = 0;
        texture->obj_rect.top = 0;
        texture->obj_rect.width = width;
        texture->obj_rect.height = height;
    }

    return texture;
}

object_t *texture_sp(char *image, int width, int height, enemy_t *mob)
{
    mob->obj->sprite_obj = sfSprite_create();
    mob->obj->textobj = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture (mob->obj->sprite_obj, mob->obj->textobj, sfTrue);
    if (width != 0 || height != 0) {
        mob->obj->obj_rect.left = 0;
        mob->obj->obj_rect.top = 0;
        mob->obj->obj_rect.width = width;
        mob->obj->obj_rect.height = height;
    }

    return mob->obj;
}