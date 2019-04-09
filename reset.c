/*
** EPITECH PROJECT, 2018
** game
** File description:
** defender game
*/

#include "include/my.h"

void dtime(game_t *game)
{
    float d_time = sfTime_asSeconds(sfClock_getElapsedTime(game->clock[1]));

    if ((d_time + game->game_stat->pause[1]) > 45) {
        game->game_stat->diff -= 0.4;
        game->game_stat->speed += 0.2;
        game->game_stat->pause[1] = 0;
        sfClock_restart(game->clock[1]);
    }
}

void resetbisbis(game_t *game, int i, int ori)
{
    if (ori == 2)
        game->game_stat->mobpv[i] = 300;
    sfSprite_setRotation(game->game_mob->mob_sprite[i], 0);
    game->game_mob->dir[i] = 'r';
    game->game_stat->lvl[i] = 0;
    if (ori == 1)
        game->game_stat->lvl[i] = 1;
    if (ori == 2)
        game->game_stat->lvl[i] = 2;
}

void resetbis(game_t *game, int i)
{
    int ori = 0;

    if (game->game_stat->speed >= 1)
        ori = 0;
    if (game->game_stat->speed >= 1.8)
        ori = rand() % 2;
    if (game->game_stat->speed >= 2.6)
        ori = rand() % 3;
    if (game->game_stat->speed >= 3.4)
        ori = ((rand() % 2) + 1);
    if (game->game_stat->speed >= 4)
        ori = 2;
    sfSprite_setPosition(game->game_mob->mob_sprite[i],
    (sfVector2f){-500, game->game_stat->hei});
    game->game_mob->mob_rect[i] =
    ((sfFloatRect){(ori * 50), 0, 50, 50});
    game->game_stat->mobpv[i] = 50;
    if (ori == 1)
        game->game_stat->mobpv[i] = 150;
    resetbisbis(game, i, ori);
}

void reset(game_t *game)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned seed;

    read(fd, &seed, sizeof seed);
    srand(seed);
    close(fd);
    if (game->game_stat->dmob == MOB) {
        game->game_stat->mob = 0;
        game->game_stat->dmob = 0;
        for (int i = 0; i != MOB; i++) {
            resetbis(game, i);
            sfSprite_setTextureRect(game->game_mob->mob_sprite[i],
            (sfIntRect){(game->game_mob->mob_rect[i]).top,
            (game->game_mob->mob_rect[i]).left,
            (game->game_mob->mob_rect[i]).height,
            (game->game_mob->mob_rect[i]).width});
        }
        sfClock_restart(game->clock[2]);
        game->game_stat->rd = 3;
    }
}
