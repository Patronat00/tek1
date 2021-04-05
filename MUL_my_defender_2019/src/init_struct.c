/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** init_struct.c
*/

#include "show.h"

obj_t *init_obj(int hp_base, int gold)
{
    obj_t *enemys = malloc (sizeof(*enemys));

    enemys->enemy = NULL;
    enemys->gold = gold;
    enemys->hp_base = hp_base;
    enemys->tower = NULL;
    return enemys;
}

map_t *init_map(int_ints_t ps, char *file)
{
    map_t *map_handle = malloc (sizeof(*map_handle));

    map_handle->grid = init_grid(20, 100.0, 20, 10);
    map_handle->m = malloc(sizeof(select_t));
    map_handle->cell = init_sprite("select.png", map_handle->grid, file);
    set_pos_map(map_handle->grid->gridesizef, map_handle->cell);
    map_handle->maps = file;
    two_d_to_one_d(file, map_handle->tab_int);
    return map_handle;
}

win_view_t *init_win_view(int x, int y, int frame, char *tag)
{
    win_view_t *show = malloc(sizeof(win_view_t));
    sfVideoMode video_mode = {x, y, frame};
    sfVector2f vi = {x, y};

    show->window = sfRenderWindow_create(video_mode, tag, sfDefaultStyle, NULL);
    show->V_view.x = vi.x / 2;
    show->V_view.y = vi.y /2;
    return show;
}

int initialize (char *file)
{
    systeme_t *sys = malloc(sizeof(*sys));

    sys->menu = malloc(sizeof(menu_t));
    sys->screen = init_map((int_ints_t) {20, 100.0, 200, 100}, file);
    sys->screen->show = init_win_view(HEIGTH, LENGTH, 32, "Tilemap");
    sys->anim_time = malloc(sizeof(timee_t));
    sys->enemy = init_obj(1, 5);
    sys->anim_time->timer = sfClock_create();
    set_button (sys->menu);
    return menu(sys);
}