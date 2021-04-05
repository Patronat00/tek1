/*
** EPITECH PROJECT, 2019
** my_runner.c
** File description:
** my_runner
*/

#include "include/my_runner.h"
#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Graphics/Export.h>
#include <time.h>
#include <SFML/System/Time.h>
#include <SFML/System/Export.h>
#include <SFML/System/Types.h>
#include <stdio.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Music.h>

int rectangle(sfSprite *sprite_2, sfIntRect *rect)
{
    sprite_text.rectrect->top = 0;
    sprite_text.rect->left = 0;
    sprite_text.rect->width = 110;
    sprite_text.rect->height = 110;
    sfSprite_setTextureRect(sprite_2, *rect);
}

int display_background_sound(sfRenderWindow *window, sfSprite *sprite, sfSprite *sprite_2) {

    sprite_text->texture = sfTexture_createFromFile("jojo_bg.jpg", NULL);
    sprite_text->texture_2 = sfTexture_createFromFile("canard.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite_text->sprite_2, sprite_text->texture_2, sfTrue);
    Soundbuffer = sfSoundBuffer_createFromFile("jojoOp1.ogg");
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->Soundbuffer);
    sfSound_play(sound->sound);
    sfSound_setLoop(sound->sound, sfTrue);
    sfSound_setVolume(sound->sound, 20);
}

int main () {
    typedef struct window window;
    typedef struct sprite_text sprite_text;
    typedef struct clock_time clock_time;
    typedef struct sound sound;
    typedef struct event_position event_position;

    if (window->window == NULL)
        return 84;
    sprite_text->sprite = sfSprite_create();
    sprite_text->sprite_2 = sfSprite_create();
    display_background_sound(window->window, sprite_text->sprite, sprite_text->sprite_2);
    event_position->offset.x = 1;
    event_position->offset.y = 0;
    clock_time->clock = sfClock_create();
    event_position->offset.x += 1;
    while (sfRenderWindow_isOpen(window->window)) {
        clock_time->time = sfClock_getElapsedTime(clock_time->clock);
        clock_time->seconds = clock_time->time.microseconds / 1000000.0;
        if (clock_time->s.econds > 0.05)
        {
            move_rect(&sprite_text->rect, 110, 330);
            sfClock_restart(clock_time->clock);
        }
        sfSprite_move(sprite_text->sprite_2, sprite_text.offset);
        event_position->sprite_position = sfSprite_getPosition(sprite_text->sprite_2);
        sfSprite_setTextureRect(sprite_text->sprite_2, sprite_text->rect);
        if (event_position->sprite_position.x >= 1920) {
            event_position->sprite_position.x = 0;
            event_position->sprite_position.y = rand() % 900;
            sfSprite_setPosition(sprite_text->sprite_2, event_position->sprite_position);
        }
        sfSprite_setPosition(sprite_text->sprite_2, event_position->sprite_position);
        sfRenderWindow_drawSprite(window->window, sprite_text->sprite, NULL);
        sfRenderWindow_drawSprite(window->window, sprite_text->sprite_2, NULL);
        //analyse_events(runner.window, runner.event, runner.sprite_position, runner.sprite_2);
        sfRenderWindow_display(window->window);
    }
    sfRenderWindow_destroy(window->window);
}