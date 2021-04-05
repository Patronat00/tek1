/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init.c
*/

#include "show.h"

void set_texture_from_pos_char
(sfSprite *sprite, sfTexture **texture, char c)
{
    char *path[] = {"grass.jpg", "road.png", NULL};

    if (c == GRASS) {
        texture[0] = sfTexture_createFromFile(path[0], NULL);
        sfSprite_setTexture(sprite, texture[0], sfTrue);
    }
    if (c == ROAD) {
        texture[1] = sfTexture_createFromFile(path[1], NULL);
        sfSprite_setTexture(sprite, texture[1], sfTrue);
    }
}

struct sfSprite ***sel_sprite(char *file, int x, int y)
{
    sfTexture *texture = NULL;
    sfSprite ***sprite = malloc(sizeof(sfSprite **) * (y + 1));

    texture = sfTexture_createFromFile(file, NULL);
    for (int i = 0; i != y + 1; i++)
        sprite[i] = malloc(sizeof(sfSprite *) * (x + 1));
    for (int my = 0; my < y; my++) {
        for (int mx = 0; mx < x; mx++) {
            sprite[my][mx] = sfSprite_create();
            sfSprite_setTexture(sprite[my][mx], texture, sfTrue);
        }
    }
    return (sprite);
}

struct sfSprite **map_sprite(int x, int y, char *file)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * (SIZE_PATH_TEXTURE));
    sfSprite **map = malloc(sizeof(sprites_t *) * (x * y + 1));
    int count = 0;

    texture[2] = NULL;
    map[x * y] = NULL;
    for (int my = 0; file[my]; my++, count++) {
        if (file[my] == '\n') {
            count--;
            continue;
        }
        map[count] = sfSprite_create();
        set_texture_from_pos_char(map[count], texture, file[my]);
    }
    return map;
}

grid_size_t *init_grid(int map_size, float gridsizef, int size_x, int size_y)
{
    grid_size_t *grid = malloc(sizeof(grid_size_t));

    grid->map_size = map_size;
    grid->gridsizeu = (unsigned)gridsizef;
    grid->gridesizef = gridsizef;
    grid->size.x = size_x;
    grid->size.y = size_y;
    return grid;
}

case_sel_t *init_sprite(char *sel, grid_size_t *grid, char *file)
{
    case_sel_t *cell = malloc(sizeof(case_sel_t));
    sfVector2f g_select = {0, 0};

    cell->map  = map_sprite(grid->size.x, grid->size.y, file);
    cell->select = sel_sprite("select.png", 1, 1);
    cell->xmax = grid->size.x;
    cell->ymax = grid->size.y;
    cell->grid_selector = g_select;
    return cell;
}