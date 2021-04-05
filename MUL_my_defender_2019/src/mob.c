/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** mob.c
*/

#include "show.h"

int search_start_enemy(int *tab_one_dimension)
{
    int y_to_2d = 0;

    for (; y_to_2d < NB_CHAR_IN_FILE; y_to_2d += X_MAX) {
        if (tab_one_dimension[y_to_2d] == ROAD_INT)
            return y_to_2d;
    }
    return 5;
}

void set_pos_mob(enemy_t *mob, int *tab_int, sfSprite **map)
{
    sfVector2f vector = sfSprite_getPosition(map[search_start_enemy(tab_int)]);

    sfSprite_setPosition(mob->obj->sprite_obj, vector);
}

void add_mob(enemy_t **index, map_t *handle_map)
{
    enemy_t *enemy = malloc(sizeof(*enemy));

    enemy->obj = texture("monster_defender/duck.png", 110, 110);
    enemy->hp = 5;
    enemy->damage = 1;
    set_pos_mob(enemy, handle_map->tab_int, handle_map->cell->map);
    enemy->next = *index;
    *index = enemy;
}

int list_count(enemy_t *index)
{
    int i = 0;

    for (enemy_t *n = index; n != NULL; i++, n = n->next);
    return i + 1;
}