/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** destroy_&_check_mob.c
*/

#include "show.h"

int check_live_mob(enemy_t *mob)
{
    return ((mob->hp <= 0) ? (0) : (1));
}

int check_mob_on_way(enemy_t *mob)
{
    return ((sfSprite_getPosition(mob->obj->sprite_obj).x >= HEIGTH)
        ? (0) : (1));
}

int destroy_mob(enemy_t *mob)
{
    destroy_obj(mob->obj);
    if (mob->next)
        free(mob->next);
}

int destroy_obj(object_t *obj)
{
    sfSprite_destroy(obj->sprite_obj);
    sfTexture_destroy(obj->textobj);
    free(obj);
}

void restart_mob(enemy_t *mob, systeme_t *sys)
{
    if (!check_mob_on_way(mob)) {
        destroy_mob(mob);
        mob = NULL;
        add_mob(&sys->enemy->enemy, sys->screen);
    }
}