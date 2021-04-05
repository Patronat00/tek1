
#ifndef LIB_H
#define LIB_H

object_t *texture(char *image, int width, int height);
void draw(menu_t *menu, sfRenderWindow *window);
map_t create_map(char *file, map_t map_d);

#endif