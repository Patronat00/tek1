//
// Created by Patronat on 2020-01-06.
//

#ifndef MUL_MY_RUNNER_2019_REAL_RUNNER_H
#define MUL_MY_RUNNER_2019_REAL_RUNNER_H

void analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f sprite_position, sfSprite *sprite_2);
int move_rect(sfIntRect *rect, int offset, int max);
int rectangle(sfSprite *sprite_2, sfIntRect *rect);
int display_background_sound(sfRenderWindow *window, sfSprite *sprite, sfSprite *sprite_2);
#endif //MUL_MY_RUNNER_2019_REAL_RUNNER_H
