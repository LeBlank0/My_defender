/*
** EPITECH PROJECT, 2018
** turret_set
** File description:
** defender turret set
*/

#include "include/my.h"

void text_loop_set(game_t *game)
{
    for (int i = 0; i != 9; i++) {
        game->game_turret->text[i] = sfText_create();
        sfText_setFont(game->game_turret->text[i], game->game_turret->font);
        sfText_setCharacterSize(game->game_turret->text[i], 70);
        if (i == 2 || i == 0)
            sfText_setCharacterSize(game->game_turret->text[i], 100);
        if (i == 3 || i == 4 || i == 5 || i == 8)
            sfText_setCharacterSize(game->game_turret->text[i], 52);
    }
    sfText_setPosition(game->game_turret->text[0], (sfVector2f){25, 915});
    sfText_setPosition(game->game_turret->text[1], (sfVector2f){1645, 922});
    sfText_setPosition(game->game_turret->text[2], (sfVector2f){220, 915});
    sfText_setPosition(game->game_turret->text[3], (sfVector2f){535, 918});
    sfText_setPosition(game->game_turret->text[4], (sfVector2f){810, 918});
    sfText_setPosition(game->game_turret->text[5], (sfVector2f){1095, 918});
    sfText_setPosition(game->game_turret->text[6], (sfVector2f){1600, 965});
    sfText_setPosition(game->game_turret->text[7], (sfVector2f){1750, 965});
    sfText_setPosition(game->game_turret->text[8], (sfVector2f){1350, 918});
}
