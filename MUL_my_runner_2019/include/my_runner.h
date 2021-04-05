/*
** EPITECH PROJECT, 2019
** my_runner.h
** File description:
** struct my_runner
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

typedef struct window
{
    sfRenderWindow *window;
    sfVideoMode mode;
}window;

typedef struct sprite_text
{
    sfSprite *sprite;
    sfSprite *sprite_2;
    sfTexture *texture;
    sfIntRect *rect;
}sprite_text;

typedef struct clock_time
{
    sfClock *clock;
    sfTime time;
    float seconds;
}clock_time;

typedef struct sound
{
    sfSoundBuffer *Soundbuffer;
    sfSound *sound;
}sound;

typedef struct event_position
{
    sfEvent event;
    sfVector2i position;
    sfVector2f sprite_position;
    sfVector2f offset;
}event_position;