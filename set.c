/*
** EPITECH PROJECT, 2018
** set
** File description:
** defender game set
*/

#include "include/my.h"

void game_home_set(game_t *game)
{
    game->game_home->home_text = sfTexture_createFromFile
    ("sprite/home.png", NULL);
    game->game_home->home_sprite = malloc(sizeof(sfSprite*) * 2);
    game->game_home->home_rect = malloc(sizeof(sfFloatRect) * 2);
    for (int i = 0; i != 2; i++) {
        game->game_home->home_sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->game_home->home_sprite[i],
        game->game_home->home_text, sfTrue);
    }
}

void game_mob_set(game_t *game)
{
    game->game_mob->dir = malloc(sizeof(char) * MOB);
    game->game_mob->mob_text = sfTexture_createFromFile
    ("sprite/mobs.png", NULL);
    game->game_mob->mob_sprite = malloc(sizeof(sfSprite*) * MOB);
    game->game_mob->mob_rect = malloc(sizeof(sfFloatRect) * MOB);
    for (int i = 0; i != MOB; i++) {
        game->game_mob->dir[i] = 'r';
        game->game_mob->mob_sprite[i] = sfSprite_create();
        sfSprite_setTexture(game->game_mob->mob_sprite[i],
        game->game_mob->mob_text, sfTrue);
        sfSprite_setOrigin(game->game_mob->mob_sprite[i],
        (sfVector2f){25, 25});
        sfSprite_setPosition(game->game_mob->mob_sprite[i],
        (sfVector2f){-500, game->game_stat->hei});
        game->game_mob->mob_rect[i] = ((sfFloatRect){0, 0, 50, 50});
        sfSprite_setTextureRect(game->game_mob->mob_sprite[i],
        (sfIntRect){(game->game_mob->mob_rect[i]).top,
        (game->game_mob->mob_rect[i]).left, (game->game_mob->mob_rect[i])
        .height, (game->game_mob->mob_rect[i]).width});
    }
}

void game_set(game_t *game, char *str)
{
    game->map = my_towordtab(get_file(str), '\n');
    game->game_stat = malloc(sizeof(*game->game_stat));
    game->game_road = malloc(sizeof(*game->game_road));
    game->game_back = malloc(sizeof(*game->game_back));
    game->game_home = malloc(sizeof(*game->game_home));
    game->game_turret = malloc(sizeof(*game->game_turret));
    game->game_mob = malloc(sizeof(*game->game_mob));
    game_stat_set(game);
    game_road_set(game);
    game_back_set(game);
    game_home_set(game);
    game_turret_set(game);
    game_mob_set(game);
    game_map_set(game);
    game->clock = malloc(sizeof(sfClock *) * 5);
    for (int i = 0; i != 5; i++)
        game->clock[i] = sfClock_create();
}

void set(sfRenderWindow *window, m_t *m)
{
    const sfImage *moon = sfImage_createFromFile("sprite/moon.png");
    const sfUint8 *icon = sfImage_getPixelsPtr(moon);

    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setIcon(window, 50, 50, icon);
    m->menu = malloc(sizeof(*m->menu));
    m->choice = malloc(sizeof(*m->choice));
    m->help = malloc(sizeof(*m->help));
    m->game = malloc(sizeof(*m->game));
    m->pause = malloc(sizeof(*m->pause));
    m->end = malloc(sizeof(*m->end));
    end_set(m->end);
    menu_set(m->menu);
    game_set(m->game, "map1.txt");
    choice_set(m->choice);
    help_set(m->help);
    pause_set(m->pause);
}
