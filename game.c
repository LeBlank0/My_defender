/*
** EPITECH PROJECT, 2018
** game
** File description:
** defender game
*/

#include "include/my.h"

void money(game_t *game)
{
    sfSprite_setColor(game->game_turret->turret_sprite[1], sfWhite);
    if (game->game_stat->coins < 100)
        sfSprite_setColor(game->game_turret->turret_sprite[1],
        sfColor_fromRGBA(229, 156, 162, 200));
    sfSprite_setColor(game->game_turret->turret_sprite[2], sfWhite);
    if (game->game_stat->coins < 200)
        sfSprite_setColor(game->game_turret->turret_sprite[2],
        sfColor_fromRGBA(229, 156, 162, 200));
    sfSprite_setColor(game->game_turret->turret_sprite[3], sfWhite);
    if (game->game_stat->coins < 400)
        sfSprite_setColor(game->game_turret->turret_sprite[3],
        sfColor_fromRGBA(229, 156, 162, 200));
    sfSprite_setColor(game->game_turret->turret_sprite[4], sfWhite);
    if (game->game_stat->coins < 800)
        sfSprite_setColor(game->game_turret->turret_sprite[4],
        sfColor_fromRGBA(229, 156, 162, 200));
}

void stat(game_t *game)
{
    float c_time = sfTime_asSeconds(sfClock_getElapsedTime(game->clock[0]));

    if ((c_time + game->game_stat->pause[0]) > 1) {
        game->game_stat->coins += 1;
        game->game_stat->pause[0] = 0;
        sfClock_restart(game->clock[0]);
    }
    if (game->game_stat->tnb >= 10)
        sfText_setPosition(game->game_turret->text[7],
        (sfVector2f){1730, 965});
    sfText_setString(game->game_turret->text[1],
    my_itoa(game->game_stat->coins));
    sfText_setString(game->game_turret->text[2],
    my_itoa(game->game_stat->score));
    sfText_setString(game->game_turret->text[7],
    my_itoa(game->game_stat->tnb));
}

void game_attack_loop(game_t *game, int i)
{
    for (int y = 0; y != game->game_stat->mob; y++)
        if (circle_contains(game, i, y) <= 250) {
            attack(game, (i - 6), y);
            return;
        }
}

void game_beam(game_t *game)
{
    if ((sfTime_asSeconds(sfClock_getElapsedTime(game->clock[4])) +
    game->game_stat->pause[3]) > 0.2)
        for (int a = 26; a != 46; a++)
            sfSprite_setColor(game->game_turret->turret_sprite[a],
            sfTransparent);
}

int game(sfRenderWindow *window, game_t *game, end_t *end)
{
    reset(game);
    stat(game);
    mob(window, game);
    for (int i = 6; i != (game->game_stat->tnb + 6); i++)
        game_follow_loop(game, i);
    game_beam(game);
    if ((sfTime_asSeconds(sfClock_getElapsedTime(game->clock[4])) +
    game->game_stat->pause[3]) > 1) {
        for (int i = 6; i != (game->game_stat->tnb + 6); i++)
            game_attack_loop(game, i);
        game->game_stat->pause[3] = 0;
        sfClock_restart(game->clock[4]);
    }
    for (int i = 0; i != game->game_stat->mob; i++)
        mob_killing(window, game, i);
    money(game);
    if (game->game_stat->health <= 0) {
        sfClock_restart(end->clock);
        sfText_setString(end->text, my_itoa(game->game_stat->score));
        return (5);
    }
    return (2);
}
