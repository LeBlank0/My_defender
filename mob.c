/*
** EPITECH PROJECT, 2018
** game
** File description:
** defender game
*/

#include "include/my.h"

void move(sfRenderWindow *window, game_t *game, int i)
{
    dir(window, game, i);

    if (game->game_mob->dir[i] == 'r')
        sfSprite_move(game->game_mob->mob_sprite[i],
        (sfVector2f){(game->game_stat->speed), 0});
    if (game->game_mob->dir[i] == 'l')
        sfSprite_move(game->game_mob->mob_sprite[i],
        (sfVector2f){-(game->game_stat->speed), 0});
    if (game->game_mob->dir[i] == 'u')
        sfSprite_move(game->game_mob->mob_sprite[i],
        (sfVector2f){0, -(game->game_stat->speed)});
    if (game->game_mob->dir[i] == 'd')
        sfSprite_move(game->game_mob->mob_sprite[i],
        (sfVector2f){0, (game->game_stat->speed)});
}

void mobmove(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i != game->game_stat->mob; i++)
        if ((get_rect(window, game->game_mob->mob_sprite[i]).left)
        < ((2500.0 / 1920.0) * (sfRenderWindow_getSize(window).x)))
            move(window, game, i);
    sfClock_restart(game->clock[3]);
}

void mob(sfRenderWindow *window, game_t *game)
{
    float s_time = sfTime_asSeconds(sfClock_getElapsedTime(game->clock[2]));
    float m_time = sfTime_asSeconds(sfClock_getElapsedTime(game->clock[3]));

    dtime(game);
    if (game->game_stat->speed > 7)
        game->game_stat->speed = 7;
    if (game->game_stat->diff < 0.3)
        game->game_stat->diff = 0.3;
    if ((s_time + game->game_stat->pause[2]) > game->game_stat->rd
    && game->game_stat->mob < MOB) {
        sfSprite_setPosition(game->game_mob->mob_sprite[game->game_stat->mob],
        (sfVector2f){-50, game->game_stat->hei});
        game->game_stat->mob += 1;
        game->game_stat->pause[2] = 0;
        game->game_stat->rd = (((rand() % 20) / 16.0) + game->game_stat->diff);
        sfClock_restart(game->clock[2]);
    }
    if (m_time > 0.01)
        mobmove(window, game);
}

void mob_killing(sfRenderWindow *window, game_t *game, int i)
{
    if (game->game_stat->mobpv[i] <= 0 && (get_rect(window,
    game->game_mob->mob_sprite[i]).left) < ((2500.0 / 1920.0) *
    (sfRenderWindow_getSize(window).x))) {
        sfSprite_setPosition(game->game_mob->mob_sprite[i],
        (sfVector2f){3000, 500});
        if (game->game_stat->lvl[i] == 0) {
            game->game_stat->coins += 8;
            game->game_stat->score += 10;
        }
        if (game->game_stat->lvl[i] == 1) {
            game->game_stat->coins += 14;
            game->game_stat->score += 20;
        }
        if (game->game_stat->lvl[i] == 2) {
            game->game_stat->coins += 18;
            game->game_stat->score += 20;
        }
        game->game_stat->dmob += 1;
    }
}
