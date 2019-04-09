/*
** EPITECH PROJECT, 2018
** set
** File description:
** defender game set
*/

#include "include/my.h"

void game_stat_set_bis(game_t *game)
{
    game->game_stat->score = 0;
    game->game_stat->dstat = 0;
    game->game_stat->cost = 0;
    game->game_stat->dmob = 0;
    game->game_stat->lvl = malloc(sizeof(int) * MOB);
    for (int i = 0; i != MOB; i++)
        game->game_stat->lvl[i] = 0;
}

void game_stat_set(game_t *game)
{
    game->game_stat->hei = height(game->map);
    game->game_stat->tnb = 0;
    game->game_stat->coins = 150;
    game->game_stat->mob = 0;
    game->game_stat->rd = 3;
    game->game_stat->diff = 5;
    game->game_stat->speed = 1;
    game->game_stat->health = 20;
    game->game_stat->pause = malloc(sizeof(float) * 4);
    for (int i = 0; i != 4; i++)
        game->game_stat->pause[i] = 0;
    game->game_stat->mobpv = malloc(sizeof(int) * MOB);
    for (int i = 0; i != MOB; i++)
        game->game_stat->mobpv[i] = 50;
    game->game_stat->type = malloc(sizeof(int) * TR);
    for (int i = 0; i != TR; i++)
        game->game_stat->type[i] = 0;
    game_stat_set_bis(game);
}
