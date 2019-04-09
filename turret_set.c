/*
** EPITECH PROJECT, 2018
** turret_set
** File description:
** defender turret set
*/

#include "include/my.h"

char const *TEXT[4] =
{"''AR 1''\n100 coins\n 12 DPS",
    "''AR 2''\n200 coins\n 25 DPS",
    "''AR 3''\n400 coins\n 55 DPS",
    " ''The King''\n  800 coins\n  115 DPS"};

void game_beam_set(game_t *game)
{
    for (int i = 26; i != 46; i++) {
        game->game_turret->turret_sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->game_turret->turret_sprite[i],
        game->game_turret->turret_text, sfTrue);
        sfSprite_setPosition(game->game_turret->turret_sprite[i], (sfVector2f)
        {-500, -500});
        game->game_turret->turret_rect[i] = ((sfFloatRect)
        {500, 0, 500, 500});
        sfSprite_setTextureRect(game->game_turret->turret_sprite[i],
        (sfIntRect){(game->game_turret->turret_rect[i]).top, (game->
        game_turret->turret_rect[i]).left, (game->game_turret->turret_rect[i])
        .height, (game->game_turret->turret_rect[i]).width});
        sfSprite_setOrigin(game->game_turret->turret_sprite[i],
        (sfVector2f){250, 250});
    }
}

void game_turret_struct_set(game_t *game)
{
    game->game_turret->turret_sprite = malloc(sizeof(sfSprite*) * 46);
    game->game_turret->turret_rect = malloc(sizeof(sfFloatRect) * 46);
    game->game_turret->turret_circle = malloc(sizeof(sfCircleShape*) * TR);
    for (int i = 0; i != TR; i++) {
        game->game_turret->turret_circle[i] = sfCircleShape_create();
        sfCircleShape_setRadius(game->game_turret->turret_circle[i], 250);
        sfCircleShape_setFillColor(game->game_turret->turret_circle[i],
        sfTransparent);
        sfCircleShape_setOutlineThickness(game->game_turret->turret_circle[i],
        4);
        sfCircleShape_setOutlineColor(game->game_turret->turret_circle[i],
        sfColor_fromRGBA(207, 58, 26, 200));
        sfCircleShape_setPosition(game->game_turret->turret_circle[i],
        (sfVector2f){-500, -500});
    }
    for (int i = 0; i != 26; i++) {
        game->game_turret->turret_sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->game_turret->turret_sprite[i],
        game->game_turret->turret_text, sfTrue);
    }
    game_beam_set(game);
}

void text_set(game_t *game)
{
    game->game_turret->turret_text =
    sfTexture_createFromFile("sprite/turret.png", NULL);
    game_turret_struct_set(game);
    sfSprite_setPosition(game->game_turret->turret_sprite[0], (sfVector2f)
    {0, 950});
    game->game_turret->turret_rect[0] = ((sfFloatRect){0, 0, 100, 1920});
    game->game_turret->text = malloc(sizeof(sfText*) * 9);
    game->game_turret->font = sfFont_createFromFile("sprite/space.ttf");
    text_loop_set(game);
    sfText_setString(game->game_turret->text[0], "Score :");
    sfText_setString(game->game_turret->text[3], TEXT[0]);
    sfText_setString(game->game_turret->text[4], TEXT[1]);
    sfText_setString(game->game_turret->text[5], TEXT[2]);
    sfText_setString(game->game_turret->text[8], TEXT[3]);
    sfText_setString(game->game_turret->text[6], "Turrets   /20");
}

void game_turret_loop_set(game_t *game)
{
    sfSprite_setScale(game->game_turret->turret_sprite[5],
    (sfVector2f){0.25, 0.25});
    game->game_turret->turret_rect[5] = ((sfFloatRect){100, 1600, 400, 400});
    sfSprite_setTextureRect(game->game_turret->turret_sprite[5],
    (sfIntRect){(game->game_turret->turret_rect[5]).top, (game->game_turret->
    turret_rect[5]).left, (game->game_turret->turret_rect[5]).height,
    (game->game_turret->turret_rect[5]).width});
    for (int i = 1; i != 5; i++) {
        sfSprite_setPosition(game->game_turret->turret_sprite[i], (sfVector2f)
        {((i * 280) + 200), 1000});
        sfSprite_setScale(game->game_turret->turret_sprite[i],
        (sfVector2f){0.2, 0.2});
        game->game_turret->turret_rect[i] = ((sfFloatRect)
        {100, ((i - 1) * 400), 400, 400});
        sfSprite_setTextureRect(game->game_turret->turret_sprite[i],
        (sfIntRect){(game->game_turret->turret_rect[i]).top, (game->
        game_turret->turret_rect[i]).left, (game->game_turret->turret_rect[i])
        .height, (game->game_turret->turret_rect[i]).width});
        sfSprite_setOrigin(game->game_turret->turret_sprite[i],
        (sfVector2f){200, 200});
    }
}

void game_turret_set(game_t *game)
{
    text_set(game);
    sfSprite_setTextureRect(game->game_turret->turret_sprite[0],
    (sfIntRect){(game->game_turret->turret_rect[0]).top, (game->game_turret->
    turret_rect[0]).left, (game->game_turret->turret_rect[0]).height,
    (game->game_turret->turret_rect[0]).width});
    sfSprite_setPosition(game->game_turret->turret_sprite[5],
    (sfVector2f){1590, 960});
    game_turret_loop_set(game);
    for (int i = 6; i != 26; i++) {
        sfSprite_setPosition(game->game_turret->turret_sprite[i], (sfVector2f)
        {-400, -400});
        sfSprite_setScale(game->game_turret->turret_sprite[i],
        (sfVector2f){0.2, 0.2});
        game->game_turret->turret_rect[i] = ((sfFloatRect)
        {0, 0, 400, 400});
        sfSprite_setTextureRect(game->game_turret->turret_sprite[i],
        (sfIntRect){(game->game_turret->turret_rect[i]).top, (game->
        game_turret->turret_rect[i]).left, (game->game_turret->turret_rect[i])
        .height, (game->game_turret->turret_rect[i]).width});
    }
}
