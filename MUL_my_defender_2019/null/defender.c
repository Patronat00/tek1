/*
** EPITECH PROJECT, 2020
** defender.c
** File description:
** main defender
*/

#include "defender.h"
#include "lib.h"


sfVector2f move_to(object_t *enemy, int x, int y)
{
        if (enemy->vect_obj.x < x && enemy->vect_obj.y < y) {
            enemy->vect_obj.x += 1;
            enemy->vect_obj.y += 1;
        } if (enemy->vect_obj.x == x && enemy->vect_obj.y < y) {
            enemy->vect_obj.y += 1;
        } if (enemy->vect_obj.y == y && enemy->vect_obj.x < x) {
            enemy->vect_obj.x += 1;
        }
        return enemy->vect_obj;
}

sfVector2f move_up(object_t *enemy, int y)
{
    if (enemy->vect_obj.y != y) enemy->vect_obj.y -= 1;
    return enemy->vect_obj;
}

enemy_t *init_mob(enemy_t *mob, int hp, int damage)
{
    enemy_t *enemy;
    enemy->obj = mob->obj;
    enemy->hp = hp;
    enemy->damage = damage;
    enemy->obj->vect_obj.x = 0;
    enemy->obj->vect_obj.y = 500;
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

enemy_t move_enemy(enemy_t mob)
{
            if (mob.obj->vect_obj.x < 270)
                mob.obj->vect_obj = move_to(mob.obj, 270, 500);
            if (mob.obj->vect_obj.x == 270 && mob.obj->vect_obj.y != 501)
                mob.obj->vect_obj = move_up(mob.obj, 200);
            if (mob.obj->vect_obj.x != 269 && mob.obj->vect_obj.y == 200)
                mob.obj->vect_obj = move_to(mob.obj, 650, 200);
            if (mob.obj->vect_obj.x == 650 && mob.obj->vect_obj.y != 199)
                mob.obj->vect_obj = move_to(mob.obj, 650, 620);
            if (mob.obj->vect_obj.x != 649 && mob.obj->vect_obj.y == 620)
                mob.obj->vect_obj = move_to(mob.obj, 1155, 620);
            if (mob.obj->vect_obj.x == 1155)
                mob.obj->vect_obj = move_up(mob.obj, 400);
            if (mob.obj->vect_obj.y == 400 && mob.obj->vect_obj.x >= 1155)
                mob.obj->vect_obj = move_to(mob.obj, 1920, 400);
            sfSprite_setPosition(mob.obj->sprite_obj, mob.obj->vect_obj);
            return mob;
}
/*
int main ()
{
    map_t map_d = create_map("map_texte.txt", map_d);
    printf("x = %d et y = %d", map_d.x, map_d.y);
}
*/

list_mob_t *init_index(void)
{
    list_mob_t *index = malloc(sizeof(index));

    index->last = NULL;
    index->first = NULL;
    return index;
}

void aj_mob(list_mob_t *index, char *str)
{
    enemy_t *node = malloc(sizeof(*node));

    node->obj = texture("monster_defender/Goomba.png", 325, 388);
    node = init_mob(node, 5, 1);
    node->next = index->first;
    index->first = node;
    if (index->last == NULL)
        index->last = node;
}

int list_count(list_mob_t *index)
{
    int i = 0;

    for (enemy_t *n = index->first; n != NULL; i++, n = n->next);
    return i + 1;
}

 /*-------------------------------------chancla---------------------------------------------*/

int main (int ac, char **av)
{
    list_mob_t *list = init_index();
    game_t *game = malloc(sizeof(game));
    char **map_s = put_map(av[1]);
}

/*

int main()
{
    list_mob_t *list = init_index();
    game_t *game = malloc(sizeof(game));
    object_t *background = malloc(sizeof(object_t));
    enemy_t meanie;
    int x = 1080;
    int y = 500;
    int d = 0;
    sfRenderWindow *window;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfClock *timer[2];
    sfTime temp[2];
    float second[2];
    int a = 0;

    for (int i = 0; i != 2; i++)
    timer[i] = sfClock_create();
    window = sfRenderWindow_create(video_mode, "The space is great",
                                  sfDefaultStyle,
                                   NULL);
    for (int i = 0; i != 5; i++) {
        aj_mob(list, "fas");
    }
    d = list_count(list);
    printf("node: %d\n", d);
    background = texture("monster_defender/map.png", 0, 0);
    game->mob.obj = texture("monster_defender/Goomba.png", 325, 388);
    sfSprite_setPosition(game->mob.obj->sprite_obj, game->mob.obj->vect_obj);
    sfRenderWindow_setFramerateLimit(window, 64);
    for (enemy_t *n = list->first; sfRenderWindow_isOpen(window);) {
        temp[0] = sfClock_getElapsedTime(timer[0]);
        temp[1] = sfClock_getElapsedTime(timer[1]);
        second[0] = temp[0].microseconds / 100000.0;
        second[1] = temp[1].microseconds / 100000.0;
        sfRenderWindow_drawSprite(window, background->sprite_obj, NULL);
//        for (enemy_t *n = list->first; n != NULL; n = n->next) {
//            printf("node: %f, %f, %d\n", n->obj->vect_obj.x, n->obj->vect_obj.y, a);
            if (n == NULL) n = list->first;
            if (second[0] > 0.2) {
                printf("node dans: %d\n", a);
                *n = move_enemy(*n);
                sfClock_restart(timer[0]);
//            }
                a++;
                sfRenderWindow_drawSprite(window, n->obj->sprite_obj, NULL);
            } if (second[1] > 5) {
                n = n->next;
                sfClock_restart(timer[1]);
            }
            for (enemy_t *na = list->first; na != NULL; na = na->next)
                sfRenderWindow_drawSprite(window, na->obj->sprite_obj, NULL);
        a = 0;
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
}
*/

