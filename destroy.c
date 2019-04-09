/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** defender game destroy
*/

#include "include/my.h"

void destroy_pause(pause_t *pause)
{
    sfTexture_destroy(pause->pause_text);
    for (int i = 0; i != 3; i++) {
        sfSprite_destroy(pause->pause_sprite[i]);
    }
    sfMusic_stop(pause->clicksound);
    sfMusic_destroy(pause->clicksound);
}

void destroy_choice(choice_t *choice)
{
    sfTexture_destroy(choice->choice_text);
    for (int i = 0; i != 3; i++) {
        sfSprite_destroy(choice->choice_sprite[i]);
    }
    sfMusic_stop(choice->clicksound);
    sfMusic_destroy(choice->clicksound);
}

void destroy_help(help_t *help)
{
    sfSprite_destroy(help->help_sprite);
    sfTexture_destroy(help->help_text);
    sfMusic_stop(help->clicksound);
    sfMusic_destroy(help->clicksound);
    for (int i = 0; i != 4; i++)
        sfText_destroy(help->text[i]);
}

void destroy_end(end_t *end)
{
    sfSprite_destroy(end->end_sprite);
    sfText_destroy(end->text);
    sfClock_destroy(end->clock);
}

void destroy_game(game_t *game)
{
    for (int i = 0; i != 5; i++)
        sfClock_destroy(game->clock[i]);
    for (int i = 0; i != (my_count(game->map, '0', 19, 36) +
    my_count(game->map, '2', 19, 36)); i++)
        sfSprite_destroy(game->game_back->back_sprite[i]);
    for (int i = 0; i != my_count(game->map, '1', 19, 36); i++)
        sfSprite_destroy(game->game_road->road_sprite[i]);
    for (int i = 0; i != MOB; i++)
        sfSprite_destroy(game->game_mob->mob_sprite[i]);
    for (int i = 0; i != 2; i++)
        sfSprite_destroy(game->game_home->home_sprite[i]);
    for (int i = 0; i != 46; i++)
        sfSprite_destroy(game->game_turret->turret_sprite[i]);
    for (int i = 0; i != 9; i++)
        sfText_destroy(game->game_turret->text[i]);
    for (int i = 0; i != TR; i++)
        sfCircleShape_destroy(game->game_turret->turret_circle[i]);
}
