/*
** EPITECH PROJECT, 2018
** game
** File description:
** defender game
*/

#include "include/my.h"

void attack(game_t *game, int a, int b)
{
    if (game->game_stat->type[a] == 1)
        game->game_stat->mobpv[b] -= 12;
    if (game->game_stat->type[a] == 2)
        game->game_stat->mobpv[b] -= 13;
    if (game->game_stat->type[a] == 3)
        game->game_stat->mobpv[b] -= 30;
    if (game->game_stat->type[a] == 4)
        game->game_stat->mobpv[b] -= 60;
    sfSprite_setColor(game->game_turret->turret_sprite[a + 26], sfWhite);
}

void follow_loop2(game_t *game, int a, int b, int p)
{
    if ((sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).top >
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).top + 50)
    && (sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).left >
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).left +
    50)) {
        sfSprite_setRotation(game->game_turret->turret_sprite[a], (90.0 + p));
        sfSprite_setRotation(game->game_turret->turret_sprite[a + 20],
        (90.0 + p));
    }
    if ((sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).top <
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).top + 50)
    && (sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).left <
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).left +
    50)) {
        sfSprite_setRotation(game->game_turret->turret_sprite[a], (270.0 + p));
        sfSprite_setRotation(game->game_turret->turret_sprite[a + 20],
        (270.0 + p));
    }
}

void follow_loop(game_t *game, int a, int b, int p)
{
    if ((sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).top <
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).top + 50)
    && (sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).left >
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).left +
    50)) {
        sfSprite_setRotation(game->game_turret->turret_sprite[a], (90.0 - p));
        sfSprite_setRotation(game->game_turret->turret_sprite[a + 20],
        (90.0 - p));
    }
    if ((sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).top >
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).top + 50)
    && (sfSprite_getGlobalBounds(game->game_mob->mob_sprite[b])).left <
    ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a])).left +
    50)) {
        sfSprite_setRotation(game->game_turret->turret_sprite[a], (270.0 - p));
        sfSprite_setRotation(game->game_turret->turret_sprite[a + 20],
        (270.0 - p));
    }
    follow_loop2(game, a, b, p);
}

void follow(game_t *game, int a, int b)
{
    float i = (((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a]))
    .top + 50) - (sfSprite_getGlobalBounds
    (game->game_mob->mob_sprite[b]).top));
    float y = (((sfSprite_getGlobalBounds(game->game_turret->turret_sprite[a]))
    .left + 50) - (sfSprite_getGlobalBounds
    (game->game_mob->mob_sprite[b]).left));
    int p = 0;

    if (i < 0)
        i = -i;
    if (y < 0)
        y = -y;
    p = ((atan(i / y) * 180.0) / M_PI);
    follow_loop(game, a , b, p);
}

void game_follow_loop(game_t *game, int i)
{
    for (int y = 0; y != game->game_stat->mob; y++)
        if (circle_contains(game, i, y) <= 250) {
            follow(game, i, y);
            return;
        }
}
