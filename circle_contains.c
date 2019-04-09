/*
** EPITECH PROJECT, 2018
** game
** File description:
** defender game
*/

#include "include/my.h"

int circle_contains(game_t *game, int a, int b)
{
    float i =
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).top
    - (sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b]).top - 20));
    float y =
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).left
    - (sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b]).left - 20));
    float res = 0;

    if (i < 0)
        i = -i;
    if (y < 0)
        y = -y;
    res = sqrtf((i * i) + (y * y));
    return (res);
}
