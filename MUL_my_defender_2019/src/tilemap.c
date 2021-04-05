/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** tilemap.c
*/

#include "show.h"

void button_close(win_view_t *show, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(show->window);
}

void show_map(case_sel_t *cell, win_view_t *show, enemy_t *list, tower_t *tower)
{
    sfRenderWindow_clear(show->window, (sfColor){0, 0, 0, 0});
    for (int y = 0; cell->map[y]; y++) {
        sfRenderWindow_drawSprite(show->window, cell->map[y], NULL);
    }
    sfRenderWindow_drawSprite(show->window, cell->select[0][0], NULL);
    for (enemy_t *n = list; n != NULL; n = n->next)
        sfRenderWindow_drawSprite(show->window, n->obj->sprite_obj, NULL);
    for (tower_t *n = tower; n != NULL; n = n->next) {
        sfRenderWindow_drawSprite(show->window, n->base->sprite_obj, NULL);
    }
    sfRenderWindow_display(show->window);
}

void check_health(systeme_t *sys, enemy_t *mob)
{
    sfVector2f vector_enemy = {0, 0};

    for (enemy_t *n = mob; n != NULL; n = n->next) {
        vector_enemy = sfSprite_getPosition(n->obj->sprite_obj);
        if (vector_enemy.x == HEIGTH)
            sys->enemy->hp_base -= mob->damage;
    }
}

int game(systeme_t *sys)
{
    enemy_t *mob = NULL;
    sfEvent event;

    add_mob(&sys->enemy->enemy, sys->screen);
    sfRenderWindow_setFramerateLimit(sys->screen->show->window, 64);
    while (sfRenderWindow_isOpen(sys->screen->show->window)) {
        spawn_time(sys->anim_time);
        sys = handle_selector(sys);
        anim_sprite(sys->enemy->enemy, sys->anim_time);
        handle_movement(sys->enemy->enemy, sys->screen->tab_int, sys->screen);
        check_health(sys, sys->enemy->enemy);
        if (!check_mob_on_way(sys->enemy->enemy)) {
            destroy_mob(sys->enemy->enemy);
            sys->enemy->enemy = NULL;
            add_mob(&sys->enemy->enemy, sys->screen);
        } put_tower_in_way(&sys->enemy->tower, event.mouseButton.type,
            sys->screen->show->window);
        while (sfRenderWindow_pollEvent(sys->screen->show->window, &event))
            button_close(sys->screen->show, event);
        show_map(sys->screen->cell, sys->screen->show,
            sys->enemy->enemy, sys->enemy->tower);
    }
}

int main (int ac, char **av)
{
    char *file;

    if (ac < 2) {
        write(1, "you forgot to add a file\n", 26);
        return 84;
    }
    if (!(file = put_map(av[1]))) {
        write(1, "put a valid map please\n", 24);
        return 84;
    }
    initialize(file);
    return (0);
}