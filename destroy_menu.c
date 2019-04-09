/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** defender game destroy
*/

#include "include/my.h"

void destroy_menu(sfRenderWindow *window, menu_t *menu, game_t *game)
{
    sfTexture_destroy(game->game_road->road_text);
    sfTexture_destroy(game->game_back->back_text);
    sfTexture_destroy(game->game_home->home_text);
    sfTexture_destroy(game->game_turret->turret_text);
    sfTexture_destroy(game->game_mob->mob_text);
    sfTexture_destroy(menu->menu_text[0]);
    sfTexture_destroy(menu->menu_text[1]);
    for (int i = 0; i != (4 + 1); i++) {
        sfSprite_destroy(menu->menu_sprite[i]);
    }
    sfClock_destroy(menu->clock_stars);
    sfMusic_stop(menu->clicksound);
    sfMusic_destroy(menu->clicksound);
    sfMusic_stop(menu->space);
    sfMusic_destroy(menu->space);
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
}
