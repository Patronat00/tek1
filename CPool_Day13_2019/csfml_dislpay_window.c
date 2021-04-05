/*
** EPITECH PROJECT, 2019
** csfml_display_window.c
** File description:
** task01Day13
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>

int main()
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    
    video_mode.width = 800;
    video_mode.height = 600;
    video_mode.bitsPerPixel = 32;
    
    video_mode.bitsPerPixel = malloc(video_mode.width * video_mode.height * video_mode.bitsPerPixel /8);
    
/*    video_mode.bitsPerPixel = 255;
      video_mode.bitsPerPixel = 125;
      video_mode.bitsPerPixel = 0;
      video_mode.bitsPerPixel = 255; */
    
    window = sfRenderWindow_create(video_mode, "My Window", sfResize | sfClose, NULL);
    
    while (sfRenderWindow_isOpen(window))
    {
        sfRenderWindow_display(window);
    }
    
    if (event.type == sfEvtClosed)                                                                            
        sfRenderWindow_close(window);
    
    sfRenderWindow_destroy(window);
    
    return EXIT_SUCCESS;
}

// to compile : gcc [namefile] -l csfml-[module_name(graphics, ...)}
