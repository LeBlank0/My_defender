/*
** EPITECH PROJECT, 2018
** parallax
** File description:
** defender game parallax
*/

#include "include/my.h"

void parallax(sfRenderWindow *window, menu_t *menu)
{
    float anim = sfTime_asSeconds(sfClock_getElapsedTime(menu->clock_stars));

    if (anim > 0.01) {
        menu->move_stars -= 1;
        sfSprite_setPosition(menu->menu_sprite[0],
        (sfVector2f){menu->move_stars, 0});
        sfRenderWindow_drawSprite(window, menu->menu_sprite[0], NULL);
        if (menu->move_stars <= -1920)
            menu->move_stars = 0;
        sfClock_restart(menu->clock_stars);
    }
}
