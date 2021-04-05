/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** set.c
*/

#include "show.h"

systeme_t *handle_selector(systeme_t *sys)
{
    sys->screen->m = set_selector(sys->screen->m,
        sys->screen->grid, sys->screen->show);
    sys->screen->cell = set_select(sys->screen->cell,
        sys->screen->grid, sys->screen->m);
    return sys;
}

timee_t *spawn_time(timee_t *time)
{
    time->temp = sfClock_getElapsedTime(time->timer);
    time->second = time->temp.microseconds / 100000.0;
    if (time->second > 3)
        time->nb++;
    return time;
}

void set_pos_map(float gride_size, case_sel_t *cell)
{
    sfVector2f posmap = {0, 0};

    for (int i = 0; cell->map[i]; i++) {
        if (posmap.x > HEIGTH) {
            posmap.x = 0;
            posmap.y += gride_size;
        }
        sfSprite_setPosition(cell->map[i], posmap);
        posmap.x += gride_size;
    }
}

select_t *set_selector(select_t *m, grid_size_t *gr, win_view_t *sh)
{
    m->mouse_ps = sfMouse_getPositionRenderWindow(NULL);
    m->mouse_pw = sfMouse_getPositionRenderWindow(sh->window);
    if (m->mouse_pw.x >= 0)
        m->mouse_pg.x = m->mouse_pw.x / gr->gridsizeu;
    if (m->mouse_pw.y >= 0)
        m->mouse_pg.y = m->mouse_pw.y / gr->gridsizeu;
    return m;
}

case_sel_t *set_select(case_sel_t *cell, grid_size_t *grid, select_t *m)
{
    cell->grid_selector.x = m->mouse_pg.x * grid->gridesizef;
    cell->grid_selector.y = m->mouse_pg.y * grid->gridesizef;
    sfSprite_setPosition(cell->select[0][0], cell->grid_selector);
    return cell;
}