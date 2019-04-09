/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** init
*/

#include "../include/rpg.h"
#include "../include/my.h"

char *intro_sprite[] = {
    "./utils/Texture/intro1.png",
    "./utils/Texture/intro2.png",
    NULL
};

char *menu_intro_sprite[] = {
    "./utils/Texture/Menu.png",
    NULL
};

char *combat_sprite[] = {
    "./utils/Texture/RPG/Sprite/Combat/back.png",
    "./utils/Texture/RPG/Sprite/Pokemon/pokemon.png",
    "./utils/Texture/RPG/Sprite/Pokemon/pokemon.png",
    "./utils/Texture/RPG/Sprite/Miscellaneous/Move_Effects.png",
    NULL
};

char *pos_combat[] = {
    "0, 0",
    "900, 300",
    "300, 900",
    "500, 500",
};

static void init_sprite_combat(main_t *m)
{
    for (size_t i = 0; i < NB_SP_COMBAT; i++) {
        TX_COMBAT[i] = sfTexture_createFromFile(combat_sprite[i], NULL);
        SP_COMBAT[i] = sfSprite_create();
        sfSprite_setTexture(SP_COMBAT[i], TX_COMBAT[i], sfTrue);
        R_COMBAT[i] = (sfIntRect){0, 0, 720, 720};
        sfSprite_setTextureRect(SP_COMBAT[i], R_COMBAT[i]);
        sfSprite_setPosition(SP_COMBAT[i],
        (sfVector2f){pos_combat[i]});
    }
}

static void init_variable_intro(main_t *m)
{
    m->intro->rect = (sfIntRect) {0, 0, 720, 720};
    GAME_SCENE = 0;
    m->game->clock = sfClock_create();
    TIME = 0;
    m->intro->i = false;
    for (int i = 0; i < 2; i += 1) {
        TX_INTRO[i] = sfTexture_createFromFile(intro_sprite[i], NULL);
        SP_INTRO[i] = sfSprite_create();
        sfSprite_setTexture(SP_INTRO[i], TX_INTRO[i], sfTrue);
        sfSprite_setTextureRect(SP_INTRO[i], m->intro->rect);
        sfSprite_setScale(SP_INTRO[i], (sfVector2f) {1.111111111,
        0.83333333});
    }
}

static void init_variable_intro_menu(main_t *m)
{
    m->menu_intro->rect = (sfIntRect) {0, 0, 800, 600};
    for (int i = 0; i < NB_SP_MENU_INTRO; i++) {
        TX_MENU_INTRO[i] = sfTexture_createFromFile(menu_intro_sprite[i], NULL);
        SP_MENU_INTRO[i] = sfSprite_create();
        sfSprite_setTexture(SP_MENU_INTRO[i], TX_MENU_INTRO[i], sfTrue);
        sfSprite_setTextureRect(SP_MENU_INTRO[i], m->menu_intro->rect);
    }
}

void init_my_var(main_t *m)
{
    init_variable_intro(m);
    init_variable_intro_menu(m);
    init_variable_game_base(m);
    init_sprite_combat(m);
}
