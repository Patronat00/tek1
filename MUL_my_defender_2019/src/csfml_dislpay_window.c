/*
** EPITECH PROJECT, 2019
** csfml_display_window.c
** File description:
** my_hunter
*/

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

void analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f sprite_position, sfSprite *sprite_2)
{
    sfVector2i position;
    sfSoundBuffer *Soundbuffer;
    sfSound *sound_dio;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed) {
            position = sfMouse_getPositionRenderWindow(window);
            if (position.x > sprite_position.x && position.x < sprite_position.x + 110 &&
                position.y > sprite_position.y && position.y < sprite_position.y + 110) {
                Soundbuffer = sfSoundBuffer_createFromFile("dio-wryyy.ogg");
                sound_dio = sfSound_create();
                sfSound_setBuffer(sound_dio, Soundbuffer);
                sfSound_play(sound_dio);
                sfSound_setVolume(sound_dio, 100);
                sprite_position.x = 0;
                sprite_position.y = rand() % 900;
                sfSprite_setPosition(sprite_2, sprite_position);
            }
        }
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

int move_rect(sfIntRect *rect, int offset, int max)
{
    rect->left += offset;
    if (rect->left >= max)
        rect->left = 0;
}

int rectangle(sfSprite *sprite_2, sfIntRect *rect)
{
    rect->top = 0;
    rect->left = 0;
    rect->width = 110;
    rect->height = 110;
    sfSprite_setTextureRect(sprite_2, *rect);
}

int display_background_sound(sfRenderWindow *window, sfSprite *sprite, sfSprite *sprite_2)
{
    sfTexture *texture;
    sfTexture *texture_2;
    sfSoundBuffer *Soundbuffer;
    sfSound *sound;

    texture = sfTexture_createFromFile("jojo_bg.jpg", NULL);
    texture_2 = sfTexture_createFromFile("canard.png", NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTexture(sprite_2, texture_2, sfTrue);
    Soundbuffer = sfSoundBuffer_createFromFile("jojoOp1.ogg");
    sound = sfSound_create();
    sfSound_setBuffer(sound, Soundbuffer);
    sfSound_play(sound);
    sfSound_setLoop(sound, sfTrue);
    sfSound_setVolume(sound, 20);
    //return (texture, texture_2, sound);
}

int main()
{
    sfTexture *texture;
    sfTexture *texture_2;
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfSound *sound;
    sfSound *sound_dio;
    sfEvent event;
    sfSprite *sprite;
    sfSprite *sprite_2;
    sfIntRect rect;
    sfSoundBuffer *Soundbuffer;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f offset;
    sfVector2f sprite_position;
    sfVector2i position;

    video_mode.width = 1920;
    video_mode.height = 1080;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "ORA ORA ORA ORA !",
                                   sfResize |
                                   sfClose, NULL);
    if (window == NULL)
        return (84);
    sprite = sfSprite_create();
    sprite_2 = sfSprite_create();
    display_background_sound(window, sprite, sprite_2);
    offset.x = 1;
    offset.y = 0;
    clock = sfClock_create();
    rectangle(sprite_2, &rect);
    offset.x += 1;
    while (sfRenderWindow_isOpen(window))
    {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        if (seconds > 0.05)
        {
            move_rect(&rect, 110, 330);
            sfClock_restart(clock);
        }
        sfSprite_move(sprite_2, offset);
        sprite_position = sfSprite_getPosition(sprite_2);
        sfSprite_setTextureRect(sprite_2, rect);
        if (sprite_position.x >= 1920) {
            sprite_position.x = 0;
            sprite_position.y = rand() %900;
            sfSprite_setPosition(sprite_2, sprite_position);
        }
        sfSprite_setPosition(sprite_2, sprite_position);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawSprite(window, sprite_2, NULL);
        analyse_events(window, event, sprite_position, sprite_2);
        sfRenderWindow_display(window);
        sfTexture_destroy(texture);
    }
    sfSoundBuffer_destroy(Soundbuffer);
    sfSound_destroy(sound);
    sfRenderWindow_destroy(window);
    sfSound_destroy(sound);
    sfSprite_destroy(sprite_2);
    sfSprite_destroy(sprite);
}