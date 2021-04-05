/*
** EPITECH PROJECT, 2020
** defender.c
** File description:
** main defender
*/

#include "defender.h"
#include "lib.h"
/*
void aj_element(index_t *index, char *str)
{
    struct enemy_t *node = malloc(sizeof(*node));
    int i;

    node->enemy = texture("monster_defender/defender1.webp", 100, 200);
    node->damage = 10;
    node->hp = 100;
    node->next = index->first;
    index->first = node;
    if (index->last == NULL)
        index->last = node;
}
*/

sfVector2f move_to(object_t *enemy, int x, int y)
{
        if (enemy->vect_obj.x < x && enemy->vect_obj.y < y) {
            enemy->vect_obj.x += 1;
            enemy->vect_obj.y += 1;
        } if (enemy->vect_obj.x <= x && enemy->vect_obj.y < y) {
            enemy->vect_obj.y += 1;
        } if (enemy->vect_obj.y <= y && enemy->vect_obj.x < x) {
            enemy->vect_obj.x += 1;
        }
        return enemy->vect_obj;
}

enemy_t init_mob(enemy_t mob, int hp, int damage)
{
    enemy_t enemy;
    enemy.obj = mob.obj;
    enemy.hp = hp;
    enemy.damage = damage;
    enemy.obj->vect_obj.x = 0;
    enemy.obj->vect_obj.y = 0;
    return enemy;
}

void att_tower(enemy_t bad, int x, int y, sfRenderWindow *window, object_t *background)
{
    while (bad.obj->vect_obj.x != x && bad.obj->vect_obj.y != y) {
        if (bad.obj->vect_obj.x < x && bad.obj->vect_obj.y < y) {
            bad.obj->vect_obj.x += 1;
            bad.obj->vect_obj.y += 1;
        } else if (bad.obj->vect_obj.x > x && bad.obj->vect_obj.y > y) {
            bad.obj->vect_obj.x -= 1;
            bad.obj->vect_obj.y -= 1;
        } if (bad.obj->vect_obj.x == x && bad.obj->vect_obj.y < y) {
            bad.obj->vect_obj.y += 1;
        } else if (bad.obj->vect_obj.x == x && bad.obj->vect_obj.y > y) {
            bad.obj->vect_obj.y -= 1;
        } if (bad.obj->vect_obj.y == y && bad.obj->vect_obj.x < x) {
            bad.obj->vect_obj.x += 1;
        } else if (bad.obj->vect_obj.y == y && bad.obj->vect_obj.x > x) {
            bad.obj->vect_obj.x -= 1;
        }
        sfSprite_setPosition(bad.obj->sprite_obj, bad.obj->vect_obj);
        sfRenderWindow_drawSprite(window, bad.obj->sprite_obj, NULL);
    }
}

int main ()
{
    game_t *game = malloc(sizeof(game));
    object_t *background = malloc(sizeof(object_t));
    enemy_t meanie;
    int x[2] = {1080, 840};
    int y[2] = {500, 480};
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};

    window = sfRenderWindow_create(video_mode, "The space is great",
                                  sfDefaultStyle,
                                   NULL);
    background = texture("start_menu/backg.jpg", 0, 0);
    game->mob.obj = texture("monster_defender/Goomba.png", 325, 388);
    game->mob = init_mob(meanie, 50, 2);
    meanie.hp = 50;
    meanie.damage = 0;
    meanie.obj->vect_obj.x = 0;
    meanie.obj->vect_obj.y = 0;
    sfSprite_setPosition(game->mob.obj->sprite_obj, game->mob.obj->vect_obj);
    sfRenderWindow_display(window); 
    sfRenderWindow_drawSprite(window, background->sprite_obj, NULL);  
    while (sfRenderWindow_isOpen(window))
    {
        /*
        if ((x[1] + y[1]) + 1000 > (meanie.obj->vect_obj.x + meanie.obj->vect_obj.y) + 1000) {
            att_tower(game->mob, x[1], y[1], window, game->background);
            return 0;
        } else {
            */
            game->mob.obj->vect_obj = move_to(game->mob.obj, x[0], y[0]);
        //}

        sfSprite_setPosition(game->mob.obj->sprite_obj, game->mob.obj->vect_obj);
//        sfRenderWindow_display(window);
//        sfRenderWindow_drawSprite(window, background->sprite_obj, NULL);
        sfRenderWindow_drawSprite(window, game->mob.obj->sprite_obj, NULL);
    }
    sfRenderWindow_destroy(window);
}