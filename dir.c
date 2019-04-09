/*
** EPITECH PROJECT, 2018
** game
** File description:
** defender game
*/

#include "include/my.h"

void dir4(sfRenderWindow *window, game_t *game, int x)
{
    int i = ((get_rect(window, game->game_mob->mob_sprite[x]).top + 1) /
    ((50.0 / 1050) * (sfRenderWindow_getSize(window).y)));
    int y = ((get_rect(window, game->game_mob->mob_sprite[x]).left + 1) /
    ((50.0 / 1920) * (sfRenderWindow_getSize(window).x)));

    if (game->game_mob->dir[x] == 'd' && game->map[i + 2][y] != '1') {
        if (game->map[i][y - 2] != '1') {
            game->game_mob->dir[x] = 'r';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 25), ((i * 50) + 25)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 0);
        }
        if (game->map[i][y + 2] != '1') {
            game->game_mob->dir[x] = 'l';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 25), ((i * 50) + 25)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 180);
        }
    }
}

void dir3(sfRenderWindow *window, game_t *game, int x)
{
    int i = ((get_rect(window, game->game_mob->mob_sprite[x]).top + 1) /
    ((50.0 / 1050) * (sfRenderWindow_getSize(window).y)));
    int y = ((get_rect(window, game->game_mob->mob_sprite[x]).left + 1) /
    ((50.0 / 1920) * (sfRenderWindow_getSize(window).x)));

    if (game->game_mob->dir[x] == 'u' && game->map[i - 1][y] != '1') {
        if (game->map[i][y - 2] != '1') {
            game->game_mob->dir[x] = 'r';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 25), ((i * 50) + 75)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 0);
        }
        if (game->map[i][y + 2] != '1') {
            game->game_mob->dir[x] = 'l';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 25), ((i * 50) + 75)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 180);
        }
    } else
        dir4(window, game, x);
}

void dir2(sfRenderWindow *window, game_t *game, int x)
{
    int i = ((get_rect(window, game->game_mob->mob_sprite[x]).top + 1) /
    ((50.0 / 1050) * (sfRenderWindow_getSize(window).y)));
    int y = ((get_rect(window, game->game_mob->mob_sprite[x]).left + 1) /
    ((50.0 / 1920) * (sfRenderWindow_getSize(window).x)));

    if (game->game_mob->dir[x] == 'l' && game->map[i][y - 1] != '1') {
        if (game->map[i + 2][y] != '1') {
            game->game_mob->dir[x] = 'u';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 75), ((i * 50) + 25)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 270);
        }
        if (game->map[i - 2][y] != '1') {
            game->game_mob->dir[x] = 'd';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 75), ((i * 50) + 25)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 90);
        }
    } else
        dir3(window, game, x);
}

void dirbis(sfRenderWindow *window, game_t *game, int x)
{
    if ((get_rect(window, game->game_mob->mob_sprite[x]).left) > ((1800.0 /
    1920.0) * (sfRenderWindow_getSize(window).x)) && (get_rect(window,
    game->game_mob->mob_sprite[x]).left) < ((2500.0 / 1920.0) *
    (sfRenderWindow_getSize(window).x))) {
        game->game_stat->health -= 1;
        game->game_stat->dmob += 1;
        sfSprite_setPosition(game->game_mob->mob_sprite[x],
        (sfVector2f){3000, 500});
    }
}

void dir(sfRenderWindow *window, game_t *game, int x)
{
    int i = ((get_rect(window, game->game_mob->mob_sprite[x]).top + 1) /
    ((50.0 / 1050) * (sfRenderWindow_getSize(window).y)));
    int y = ((get_rect(window, game->game_mob->mob_sprite[x]).left + 1) /
    ((50.0 / 1920) * (sfRenderWindow_getSize(window).x)));

    dirbis(window, game, x);
    if (game->game_mob->dir[x] == 'r' && game->map[i][y + 2] != '1' && y < 34){
        if (game->map[i + 2][y] != '1') {
            game->game_mob->dir[x] = 'u';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 25), ((i * 50) + 25)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 270);
        }
        if (game->map[i - 2][y] != '1') {
            game->game_mob->dir[x] = 'd';
            sfSprite_setPosition(game->game_mob->mob_sprite[x],
            (sfVector2f){((y * 50) + 25), ((i * 50) + 25)});
            sfSprite_setRotation(game->game_mob->mob_sprite[x], 90);
        }
    } else
        dir2(window, game, x);
}
