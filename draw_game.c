/*
** EPITECH PROJECT, 2018
** draw
** File description:
** defender game draw
*/

#include "include/my.h"

void draw_game(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i != (my_count(game->map, '0', 19, 36) +
    my_count(game->map, '2', 19, 36)); i++)
        sfRenderWindow_drawSprite(window,
        game->game_back->back_sprite[i], NULL);
    for (int i = 0; i != my_count(game->map, '1', 19, 36); i++)
        sfRenderWindow_drawSprite(window,
        game->game_road->road_sprite[i], NULL);
    for (int i = 0; i != game->game_stat->mob; i++)
        sfRenderWindow_drawSprite(window, game->game_mob->mob_sprite[i], NULL);
    for (int i = 0; i != 2; i++)
        sfRenderWindow_drawSprite(window,
        game->game_home->home_sprite[i], NULL);
    for (int i = 0; i != 46; i++)
        sfRenderWindow_drawSprite(window,
        game->game_turret->turret_sprite[i], NULL);
    for (int i = 0; i != 9; i++)
        sfRenderWindow_drawText(window, game->game_turret->text[i], NULL);
    for (int i = 0; i != (game->game_stat->tnb + 1)
    && game->game_stat->tnb < 20; i++)
        sfRenderWindow_drawCircleShape(window,
        game->game_turret->turret_circle[i], NULL);
}
