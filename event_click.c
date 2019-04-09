/*
** EPITECH PROJECT, 2018
** event
** File description:
** defender game event
*/

#include "include/my.h"

int price(int i)
{
    if (i == 1)
        return (100);
    if (i == 2)
        return (200);
    if (i == 3)
        return (400);
    if (i == 4)
        return (800);
    return (100);
}

int menu_event_click(sfEvent event, int i, int stat)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (i == 1)
            stat = 4;
        if (i == 2)
            stat = 1;
        if (i == 3) {
            sfSleep((sfTime){200000});
            stat = 84;
        }
    }
    return (stat);
}

int choice_event_click(game_t *game, sfEvent event, int i, int stat)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (i == 0) {
            stat = 2;
            game_set(game, "map1.txt");
            sfSleep((sfTime){200000});
        }
        if (i == 1) {
            stat = 2;
            game_set(game, "map2.txt");
            sfSleep((sfTime){200000});
        }
        if (i == 2) {
            stat = 2;
            game_set(game, "map3.txt");
            sfSleep((sfTime){200000});
        }
    }
    return (stat);
}

int pause_event_click(game_t *game, sfEvent event, int i, int stat)
{
    if (event.type == sfEvtMouseButtonReleased) {
        if (i == 0) {
            stat = 2;
            sfClock_restart(game->clock[0]);
            sfClock_restart(game->clock[1]);
            sfClock_restart(game->clock[2]);
            sfClock_restart(game->clock[3]);
            sfClock_restart(game->clock[4]);
            sfSleep((sfTime){200000});
        }
        if (i == 1) {
            sfSleep((sfTime){200000});
            stat = 0;
        }
        if (i == 2) {
            sfSleep((sfTime){200000});
            stat = 84;
        }
    }
    return (stat);
}

void turret_event_click(game_t *game, sfEvent event, int i)
{
    int a = price(i);

    if (event.type == sfEvtMouseButtonPressed && game->game_stat->coins >= a
    && game->game_stat->tnb < TR) {
        game->game_stat->cost = a;
        game->game_turret->turret_rect[game->game_stat->tnb + 6] =
        ((sfFloatRect){100, ((i - 1) * 400), 400, 400});
        game->game_turret->turret_rect[game->game_stat->tnb + 26] =
        ((sfFloatRect){500, ((i - 1) * 500), 500, 500});
        sfSprite_setTextureRect(game->game_turret->turret_sprite
        [game->game_stat->tnb + 6], (sfIntRect){(game->game_turret->turret_rect
        [game->game_stat->tnb + 6]).top, (game->game_turret->turret_rect
        [game->game_stat->tnb + 6]).left, (game->game_turret->turret_rect
        [game->game_stat->tnb + 6]).height, (game->game_turret->turret_rect
        [game->game_stat->tnb + 6]).width});
        game->game_stat->type[game->game_stat->tnb] = i;
        sfSprite_setColor(game->game_turret->turret_sprite
        [game->game_stat->tnb + 6], sfColor_fromRGBA (255, 255, 255, 150));
        sfCircleShape_setOutlineColor(game->game_turret->turret_circle
        [game->game_stat->tnb], sfColor_fromRGBA(207, 58, 26, 200));
        game->game_stat->dstat = 1;
    }
}
