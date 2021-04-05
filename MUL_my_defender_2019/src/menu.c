/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** menu.c
*/

#include "show.h"

void m_free (int *choice, menu_t *menu, sprites_t *vector, char **map)
{
    free(map);
    free(choice);
    free(menu);
    free(vector);
}

int *f_event(sfEvent event, int *choice, sfRenderWindow *window)
{
    sfVector2i position = {0, 0};

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            position = sfMouse_getPositionRenderWindow(window);
            if ((position.y >= 303 && position.y <= 366) &&
                (position.x >= 800 && position.x < 1015))
                choice[0] = 1;
            if ((position.y > 439 && position.y < 500) &&
                (position.x > 800 && position.x < 1015))
                choice[1] = 2;
            if (position.y >= 569 && position.y < 633 &&
                position.x >= 800 && position.x <= 1015)
                choice[2] = 3;
        }
        if (event.type == sfEvtClosed)
            choice[2] = 3;
    }
    return choice;
}

void draw(menu_t *menu, sfRenderWindow *window)
{
    sfRenderWindow_display(window);
    sprite_positions(menu);
    sfRenderWindow_drawSprite(window, menu->backg->sprite_obj, NULL);
    sfRenderWindow_drawSprite(window, menu->quit->sprite_obj, NULL);
    sfRenderWindow_drawSprite(window, menu->help->sprite_obj, NULL);
    sfRenderWindow_drawSprite(window, menu->play->sprite_obj, NULL);
}

void set_button (menu_t *menu)
{
    menu->backg = texture("start_menu/backg.jpg", 0, 0);
    menu->quit = texture("start_menu/exit.png", 356, 141);
    menu->help = texture("start_menu/help.png", 229, 65);
    menu->play = texture("start_menu/play.png", 510, 165);
}

int menu(systeme_t *sys)
{
    int *choice = malloc (sizeof(int) * 3);
    sfEvent event;

    choice[0] = 0;
    choice[2] = 0;
    while (sfRenderWindow_isOpen(sys->screen->show->window)) {
        draw (sys->menu, sys->screen->show->window);
        choice = f_event(event, choice, sys->screen->show->window);
        if (choice[0] == 1) {
            game(sys);
            return (0);
            choice[0] = 0;
        } if (choice[2] == 3) {
            sfRenderWindow_close(sys->screen->show->window);
            return 0;
        }
    }
}
