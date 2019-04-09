/*
** EPITECH PROJECT, 2018
** event
** File description:
** defender game event
*/

#include "include/my.h"

void turret_pos_r_2(sfRenderWindow *window, game_t *game)
{
    sfSprite_setOrigin(game->game_turret->turret_sprite
    [game->game_stat->tnb + 6], (sfVector2f){200, 200});
    game->game_turret->turret_rect[game->game_stat->tnb + 6] =
    get_rect(window, game->game_turret->turret_sprite
    [game->game_stat->tnb + 6]);
    sfCircleShape_setPosition(game->game_turret->turret_circle
    [game->game_stat->tnb], (sfVector2f){((sfSprite_getGlobalBounds
    (game->game_turret->turret_sprite[game->game_stat->tnb + 6]).left)
    - 210.0), ((sfSprite_getGlobalBounds(game->game_turret->
    turret_sprite[game->game_stat->tnb + 6]).top) - 210.0)});
    game->game_stat->tnb += 1;
    game->game_stat->coins -= game->game_stat->cost;
}

void turret_pos_r(sfRenderWindow *window, game_t *game, int i, int y)
{
    game->map[i][y] = '2';
    game->map[i][y + 1] = '2';
    game->map[i + 1][y] = '2';
    game->map[i + 1][y + 1] = '2';
    sfSprite_setPosition(game->game_turret->turret_sprite[game->game_stat->tnb
    + 6], (sfVector2f){((y * 50) + 50), ((i * 50) + 50)});
    sfSprite_setPosition(game->game_turret->turret_sprite
    [game->game_stat->tnb + 26],
    (sfVector2f){((y * 50) + 50), ((i * 50) + 50)});
    sfSprite_setTextureRect(game->game_turret->turret_sprite[game->game_stat
    ->tnb + 26], (sfIntRect){(game->game_turret->turret_rect[game->game_stat->
    tnb + 26]).top, (game-> game_turret->turret_rect[game->game_stat->tnb +
    26]).left, (game->game_turret->turret_rect[game->game_stat->tnb + 26])
    .height, (game->game_turret->turret_rect[game->game_stat->tnb +
    26]).width});
    turret_pos_r_2(window, game);
}

void turret_pos(sfRenderWindow *window, game_t *game)
{
    int i = (game->pos_mous.y / ((50.0 / 1050.0) *
    (sfRenderWindow_getSize(window).y)));
    int y = (game->pos_mous.x / ((50.0 / 1920.0) *
    (sfRenderWindow_getSize(window).x)));

    if (i < 18 && y < 35) {
        if (game->map[i][y] < '1' && game->map[i][y + 1] < '1'
        && game->map[i + 1][y] < '1' && game->map[i + 1][y + 1] < '1')
            turret_pos_r(window, game, i, y);
        else
            sfCircleShape_setPosition(game->game_turret->turret_circle
            [game->game_stat->tnb],
            (sfVector2f){-500, -500});
    }
    else
        sfCircleShape_setPosition(game->game_turret->turret_circle
        [game->game_stat->tnb],
        (sfVector2f){-500, -500});
}

void turret_event_rect(sfRenderWindow *window, game_t *game, sfEvent event)
{
    for (int i = 1; i != 5; i++)
        game->game_turret->turret_rect[i] = get_rect(window,
        game->game_turret->turret_sprite[i]);
    for (int i = 6; i != (game->game_stat->tnb + 6); i++)
        game->game_turret->turret_rect[i] = get_rect(window,
        game->game_turret->turret_sprite[i]);
    for (int i = 1; i != 5; i++) {
        if (sfFloatRect_contains(&game->game_turret->turret_rect[i],
        game->pos_mous.x, game->pos_mous.y)) {
            sfSprite_setScale(game->game_turret->turret_sprite[i], (sfVector2f)
            {0.21, 0.21});
            turret_event_click(game, event, i);
        } else
            sfSprite_setScale(game->game_turret->turret_sprite[i],
            (sfVector2f){0.2, 0.2});
    }
}

void turret_event_dstat(sfRenderWindow *window, game_t *game)
{
    if (game->game_stat->dstat == 1) {
        sfSprite_setPosition(game->game_turret->turret_sprite[game->
        game_stat->tnb + 6], (sfVector2f){(((game->pos_mous.x * 1920.0) /
        (sfRenderWindow_getSize(window)).x) - 15), (((game->pos_mous.y *
        1050.0) / (sfRenderWindow_getSize(window)).y) - 15)});
        game->game_turret->turret_rect[game->game_stat->tnb + 6] =
        get_rect(window, game->game_turret->turret_sprite
        [game->game_stat->tnb + 6]);
        sfCircleShape_setPosition(game->game_turret->turret_circle
        [game->game_stat->tnb],
        (sfVector2f){((sfSprite_getGlobalBounds(game->game_turret->
        turret_sprite[game->game_stat->tnb + 6]).left) - 210.0),
        ((sfSprite_getGlobalBounds(game->game_turret->turret_sprite
        [game->game_stat->tnb + 6]).top) - 210.0)});
    }
}
