/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** move enemy.c
*/

#include "show.h"

void move_enemy(enemy_t *n, int *tab_int, int x, int y)
{
        sfSprite_move(n->obj->sprite_obj, (sfVector2f) {x, y});
}

int check_position(sfSprite *find, sfSprite *src)
{
    sfVector2f vector_find = sfSprite_getPosition(find);
    sfVector2f vector_src = sfSprite_getPosition(src);

    if (vector_find.x >= vector_src.x &&
        vector_find.x <= vector_src.x + SIZE_WIDTH_PIXE)
        if (vector_find.y + SIZE_HEIGTH_PIXE >= vector_src.y &&
            vector_find.y + SIZE_HEIGTH_PIXE <= vector_src.y + SIZE_HEIGTH_PIXE)
            return 1;
    return 0;
}

int find_position(sfSprite **map, enemy_t *mob)
{
    for (int i = 0; map[i] != NULL; i++)
        if (check_position(mob->obj->sprite_obj, map[i]))
            return i;
    return -1;
}

void handle_movement(enemy_t *enemys, int *tab, map_t *map)
{
    int result = 0;
    static int up_or_down = 0;

    for (enemy_t *mob = enemys; mob !=  NULL; mob = mob->next) {
        if ((result = find_position(map->cell->map, mob)) == -1)
            break;
        if (tab[(result + 1)] == ROAD_INT) {
            move_enemy(mob, tab, 5, 0);
            up_or_down = 0;
            break;
        } if (tab[(result + X_MAX)] == ROAD_INT &&
            (up_or_down == -1 || up_or_down == 0)) {
            move_enemy(mob, tab, 0, 5);
            up_or_down = -1;
        } else if (tab[(result - X_MAX)] == ROAD_INT &&
            (up_or_down == 1 || up_or_down == 0)) {
            move_enemy(mob, tab, 0, -5);
            up_or_down = 1;
        }
    }
}