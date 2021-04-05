/*
** EPITECH PROJECT, 2020
** menu.c
** File description:
** fas
*/

#include "defender.h"
#include "include/my.h"

map_t create_map(char *file, map_t map_d)
{
    char **maped = NULL;
    size_t s = 0;
    FILE *fd = fopen(file, "r");
    
    for(int y = 0; getline(&maped[y], &s, fd) != -1; y++);
    map_d.map = maped;
    printf("%s", maped[0]);
    map_d.y = 0;
    for (; maped[map_d.y][0] != 1; map_d.y++)
    printf("oui");
    map_d.x = 0;
    return map_d;
}

int *f_event(sfEvent event, sprites_t *vectors, int *choice, sfRenderWindow *window)
{
    sfVector2i position;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            position = sfMouse_getPositionRenderWindow(window);
            printf("\n%d position.x\n", position.x);
            printf("%d position.y\n", position.y);
            if ((position.y >= 303 && position.y <= 366) &&
                (position.x >= 800 && position.x < 1015))
                choice[0] = 1;
            if ((position.y > 439 && position.y < 500) &&
                (position.x > 800 && position.x < 1015))
                choice[1] = 2;
            if (position.y >= 569 && position.y < 633 &&
                position.x >= 800 && position.x <= 1015) {
                choice[2] = 3;
            }
        }
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
    return choice;
}

object_t *texture(char *image, int width, int height)
{
    object_t *texture = malloc(sizeof(object_t));

    texture->sprite_obj = sfSprite_create();
    texture->textobj = sfTexture_createFromFile(image, NULL);
    sfSprite_setTexture (texture->sprite_obj, texture->textobj, sfTrue);
    if (width != 0 || height != 0) {
        texture->obj_rect.left = 0;
        texture->obj_rect.top = 0;
        texture->obj_rect.width = width;
        texture->obj_rect.height = height;
    }

    return texture;
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

int sauce(int ac, char **av)
{
    sfRenderWindow *window;
    int *choice = malloc (sizeof(int) * 3);
    menu_t *menu = malloc (sizeof(menu));
    sfEvent event;
    sfVideoMode video_mode = {1920, 1080, 32};
    sprites_t *vectors = malloc(sizeof(sprites_t));
 
    window = sfRenderWindow_create(video_mode, "The space is great",
                                   sfDefaultStyle,
                                   NULL);
    menu->backg = texture("start_menu/backg.jpg", 0, 0);
    menu->quit = texture("start_menu/exit.png", 356, 141);
    menu->help = texture("start_menu/help.png", 229, 65);
    menu->play = texture("start_menu/play.png", 510, 165);
    while (sfRenderWindow_isOpen(window)) {
        draw (menu, window);
        choice = f_event(event, vectors, choice, window);
        if (choice[0] == 1) {
            open_file(ac, av, choice);
        }
        if (choice[2] == 3) {
            free(choice);
            sfRenderWindow_close(window);
            return 0;
        }
    }
}
