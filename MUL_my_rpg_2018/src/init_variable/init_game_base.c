/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init_game_base
*/

#include "../include/rpg.h"
#include "../include/my.h"

static void init_map(main_t *m)
{
    m->my_game->map_sprite = sfSprite_create();
    m->my_game->map_texture =
    sfTexture_createFromFile("./utils/game_play/map_p.png", NULL);
    sfSprite_setTexture(m->my_game->map_sprite, m->my_game->map_texture,
    sfTrue);
    m->my_game->rect_map = (sfIntRect){0, 0, 500, 500};
    sfSprite_setTextureRect(m->my_game->map_sprite, m->my_game->rect_map);
    sfSprite_setScale(m->my_game->map_sprite, (sfVector2f){1.68, 1.5});
}

static void init_sacha(main_t *m)
{
    m->my_game->sacha_sprite = sfSprite_create();
    m->my_game->sacha_texture =
    sfTexture_createFromFile("./utils/game_play/sacha.png", NULL);
    sfSprite_setTexture(m->my_game->sacha_sprite, m->my_game->sacha_texture,
    sfTrue);
    m->my_game->rect_sacha = (sfIntRect){0, 0, 15, 22};
    sfSprite_setTextureRect(m->my_game->sacha_sprite, m->my_game->rect_sacha);
    sfSprite_setScale(m->my_game->sacha_sprite, (sfVector2f){1.68, 1.5});
    sfSprite_setPosition(m->my_game->sacha_sprite, (sfVector2f){385, 200});
}

void init_variable_game_base(main_t *m)
{
    init_map(m);
    init_sacha(m);
}
