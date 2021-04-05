/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** norme.c
*/

#include "show.h"

void anim_sprite(enemy_t *list, timee_t *anim_time)
{
    for (enemy_t *mob = list; mob != NULL; mob = mob->next) {
        anim_time->temp = sfClock_getElapsedTime(anim_time->timer);
        anim_time->second = anim_time->temp.microseconds / 1000000.0;
        if (anim_time->second > 0.10) {
            move_rect(&mob->obj->obj_rect, 110, 330);
            sfSprite_setTextureRect(mob->obj->sprite_obj , mob->obj->obj_rect);
            sfClock_restart(anim_time->timer);
        }
    }
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - offset)
        rect->left += offset;
    else
        rect->left = 0;
}

sfIntRect create_rect
(int offsetTop, int offsetLeft, int offsetWidth, int offsetHeight)
{
    sfIntRect rect;

    rect.top = offsetTop;
    rect.left = offsetLeft;
    rect.width = offsetWidth;
    rect.height = offsetHeight;
    return rect;
}
