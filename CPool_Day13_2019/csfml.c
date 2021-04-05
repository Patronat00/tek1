/*
** EPITECH PROJECT, 2019
** csfml.c
** File description:
** graphics
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

{
    int width;
    int height ;
    int bitsPerPixel;

    sfUint8 *pixels;

    width = 800;
    height = 600;
    bitsPerPixel = 32;

    pixels = malloc(width * height * bitsPerPixel /8);

    pixels[0] = 255;
    pixels[1] = 125;
    pixels[2] = 0;
    pixels[3] = 255;

    display_framebuffer(pixels, width, height);
}
