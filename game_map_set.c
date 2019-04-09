/*
** EPITECH PROJECT, 2018
** set
** File description:
** defender game set
*/

#include "include/my.h"

void game_road_set(game_t *game)
{
    game->game_road->nbb = 0;
    game->game_road->nbr = 0;
    game->game_road->road_text = sfTexture_createFromFile
    ("sprite/road.png", NULL);
    game->game_road->road_sprite = malloc(sizeof(sfSprite*) *
    (my_count(game->map, '1', 19, 36)));
    game->game_road->road_rect = malloc(sizeof(sfFloatRect) *
    (my_count(game->map, '1', 19, 36)));
    for (int i = 0; i != (my_count(game->map, '1', 19, 36)); i++) {
        game->game_road->road_sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->game_road->road_sprite[i],
        game->game_road->road_text, sfTrue);
    }
}

void game_back_set(game_t *game)
{
    game->game_back->back_text = sfTexture_createFromFile
    ("sprite/background.png", NULL);
    game->game_back->back_sprite = malloc(sizeof(sfSprite*) *
    (my_count(game->map, '0', 19, 36)));
    game->game_back->back_rect = malloc(sizeof(sfFloatRect) *
    (my_count(game->map, '0', 19, 36)));
    for (int i = 0; i != (my_count(game->map, '0', 19, 36)); i++) {
        game->game_back->back_sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->game_back->back_sprite[i],
        game->game_back->back_text, sfTrue);
    }
}
