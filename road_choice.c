/*
** EPITECH PROJECT, 2018
** road_choice
** File description:
** defender map road choice
*/

#include "include/my.h"

int angle_width(game_t *game, int i, int y, int a)
{
    a = (game->map[i - 1][y] == '1' && game->map[i][y + 1] == '1'
    && game->map[i + 1][y] == '1' && game->map[i][y - 1] == '1' &&
    game->map[i - 1][y - 1] == '0') ? 150 : a;
    a = (game->map[i - 1][y] == '1' && game->map[i][y + 1] == '1'
    && game->map[i + 1][y] == '1' && game->map[i][y - 1] == '1' &&
    game->map[i + 1][y - 1] == '0') ? 200 : a;
    a = (game->map[i - 1][y] == '1' && game->map[i][y + 1] == '1'
    && game->map[i + 1][y] == '1' && game->map[i][y - 1] == '1' &&
    game->map[i - 1][y + 1] == '0') ? 250 : a;
    a = (game->map[i - 1][y] == '1' && game->map[i][y + 1] == '1'
    && game->map[i + 1][y] == '1' && game->map[i][y - 1] == '1' &&
    game->map[i + 1][y + 1] == '0') ? 300 : a;
    return (a);
}

int road_height(game_t *game, int i, int y)
{
    int a = 50;

    a = (game->map[i - 1][y] == '0' && game->map[i][y + 1] == '1'
    && game->map[i + 1][y] == '1' && game->map[i][y - 1] == '0') ?
    0 : a;
    a = (game->map[i - 1][y] == '0' && (game->map[i][y + 1] == '1'
    || y == (MW - 1)) && game->map[i + 1][y] == '1'
    && (game->map[i][y - 1] == '1' || y == 0)) ? 0 : a;
    a = (game->map[i - 1][y] == '0' && game->map[i][y + 1] == '0'
    && game->map[i + 1][y] == '1' && game->map[i][y - 1] == '1') ?
    0 : a;
    a = (game->map[i + 1][y] == '0' && game->map[i][y + 1] == '1'
    && game->map[i - 1][y] == '1' && game->map[i][y - 1] == '0') ?
    100 : a;
    a = (game->map[i + 1][y] == '0' && (game->map[i][y + 1] == '1'
    || y == (MW - 1)) && game->map[i - 1][y] == '1'
    && (game->map[i][y - 1] == '1' || y == 0)) ? 100 : a;
    a = (game->map[i + 1][y] == '0' && game->map[i][y + 1] == '0'
    && game->map[i - 1][y] == '1' && game->map[i][y - 1] == '1') ?
    100 : a;
    return (a);
}

int road_width(game_t *game, int i, int y)
{
    int a = 50;

    a = (game->map[i - 1][y] == '0' && game->map[i][y + 1] == '1'
    && game->map[i + 1][y] == '1' && game->map[i][y - 1] == '0') ?
    0 : a;
    a = ((game->map[i - 1][y] == '1' || i == 0) && game->map[i][y + 1] == '1'
    && (game->map[i + 1][y] == '1' || i == MH) && game->map[i][y - 1] == '0') ?
    0 : a;
    a = (game->map[i - 1][y] == '1' && game->map[i][y + 1] == '1' &&
    game->map[i + 1][y] == '0' && game->map[i][y - 1] == '0') ? 0 : a;
    a = (game->map[i - 1][y] == '0' && game->map[i][y - 1] == '1'
    && game->map[i + 1][y] == '1' && game->map[i][y + 1] == '0') ?
    100 : a;
    a = ((game->map[i - 1][y] == '1' || i == 0) && game->map[i][y - 1] == '1'
    && (game->map[i + 1][y] == '1' || i == MH) && game->map[i][y + 1] == '0') ?
    100 : a;
    a = (game->map[i - 1][y] == '1' && game->map[i][y - 1] == '1' &&
    game->map[i + 1][y] == '0' && game->map[i][y + 1] == '0') ? 100 : a;
    a = angle_width(game, i, y, a);
    return (a);
}
