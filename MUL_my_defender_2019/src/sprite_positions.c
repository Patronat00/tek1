/*
** EPITECH PROJECT, 2020
** sprite_positions.c
** File description:
** set positions of sprites
*/

#include "show.h"

sprites_t *sprite_positions(menu_t *menu)
{
    sprites_t *vectors = malloc(sizeof(sprites_t));

    vectors->sprite_position_play.x = 800;
    vectors->sprite_position_play.y = 320;
    vectors->sprite_position_help.x = 800;
    vectors->sprite_position_help.y = 460;
    vectors->sprite_position_exit.x = 800;
    vectors->sprite_position_exit.y = 600;
    sfSprite_setPosition(menu->help->sprite_obj, vectors->sprite_position_help);
    sfSprite_setPosition(menu->quit->sprite_obj, vectors->sprite_position_exit);
    sfSprite_setPosition(menu->play->sprite_obj, vectors->sprite_position_play);
}
