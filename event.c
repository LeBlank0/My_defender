/*
** EPITECH PROJECT, 2018
** event
** File description:
** defender game event
*/

#include "include/my.h"

void turret_event(sfRenderWindow *window, game_t *game, sfEvent event)
{
    turret_event_rect(window, game, event);
    for (int i = 6; i != (game->game_stat->tnb + 6); i++) {
        if (sfFloatRect_contains(&game->game_turret->turret_rect[i],
        game->pos_mous.x, game->pos_mous.y))
            sfCircleShape_setOutlineColor(game->game_turret->turret_circle
            [i - 6], sfColor_fromRGBA(207, 58, 26, 200));
        else
            sfCircleShape_setOutlineColor(game->game_turret->turret_circle
            [i - 6], sfColor_fromRGBA(207, 58, 26, 0));
    }
    turret_event_dstat(window, game);
    if (event.type == sfEvtMouseButtonReleased
    && game->game_stat->dstat == 1) {
        sfSprite_setPosition(game->game_turret->turret_sprite[game->game_stat
        ->tnb + 6], (sfVector2f){-400, -400});
        sfSprite_setColor(game->game_turret->turret_sprite[game->game_stat
        ->tnb + 6], sfWhite);
        turret_pos(window, game);
        game->game_stat->dstat = 0;
    }
}

void game_event_rect(sfRenderWindow *window, game_t *game)
{
    for (int i = 0; i != (my_count(game->map, '0', 19, 36) +
    my_count(game->map, '2', 19, 36)); i++) {
        game->game_back->back_rect[i] = get_rect(window,
        game->game_back->back_sprite[i]);
        if (sfFloatRect_contains(&game->game_back->back_rect[i],
        game->pos_mous.x, game->pos_mous.y))
            sfSprite_setColor(game->game_back->back_sprite[i], sfColor_fromRGBA
            (255, 255, 255, 150));
        else
            sfSprite_setColor(game->game_back->back_sprite[i], sfWhite);
    }
}

int game_event(sfRenderWindow *window, game_t *game, sfEvent event, int stat)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape) {
        stat = 3;
        for (int i = 0; i != 3; i++)
            game->game_stat->pause[i] +=
            sfTime_asSeconds(sfClock_getElapsedTime(game->clock[i]));
        game->game_stat->pause[3] +=
        sfTime_asSeconds(sfClock_getElapsedTime(game->clock[4]));
    }
    game_event_rect(window, game);
    for (int i = 0; i != my_count(game->map, '1', 19, 36); i++) {
        game->game_road->road_rect[i] = get_rect(window,
        game->game_road->road_sprite[i]);
        if (sfFloatRect_contains(&game->game_road->road_rect[i],
        game->pos_mous.x, game->pos_mous.y))
            sfSprite_setColor(game->game_road->road_sprite[i], sfColor_fromRGBA
            (255, 255, 255, 150));
        else
            sfSprite_setColor(game->game_road->road_sprite[i], sfWhite);
    }
    turret_event(window, game, event);
    return (stat);
}
