/*
** EPITECH PROJECT, 2018
** set
** File description:
** defender game set
*/

#include "include/my.h"

void menu_loop_set(menu_t *menu)
{
    for (int i = 1; i != 4; i++) {
        menu->menu_sprite[i] = sfSprite_create();
        sfSprite_setTexture(menu->menu_sprite[i]
        , menu->menu_text[1], sfTrue);
        sfSprite_setPosition(menu->menu_sprite[i],
        (sfVector2f){((i * 500) - 240), 860});
        menu->menu_rect[i] = (sfFloatRect){(i - 1) * 116, 387, 116, 387};
        if (i == 3)
            menu->menu_rect[i] = (sfFloatRect){232, 0, 116, 387};
        sfSprite_setTextureRect(menu->menu_sprite[i],
        (sfIntRect){(menu->menu_rect[i]).top, (menu->menu_rect[i]).left,
        (menu->menu_rect[i]).height, (menu->menu_rect[i]).width});
    }
}

void menu_set(menu_t *menu)
{
    menu->space = sfMusic_createFromFile("sprite/stars.ogg");
    menu->clicksound = sfMusic_createFromFile("sprite/click.ogg");
    menu->clock_stars = sfClock_create();
    menu->menu_sprite = malloc(sizeof(sfSprite*) * 5);
    menu->menu_text = malloc(sizeof(sfTexture*) * 3);
    menu->menu_rect = malloc(sizeof(sfFloatRect) * 4);
    menu->menu_text[0] = sfTexture_createFromFile("sprite/stars.png", NULL);
    menu->menu_text[1] = sfTexture_createFromFile("sprite/button.png", NULL);
    menu->menu_sprite[0] = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite[0], menu->menu_text[0], sfTrue);
    menu_loop_set(menu);
    menu->menu_text[2] = sfTexture_createFromFile("sprite/logo.png", NULL);
    menu->menu_sprite[4] = sfSprite_create();
    sfSprite_setTexture(menu->menu_sprite[4], menu->menu_text[2], sfTrue);
    sfSprite_setPosition(menu->menu_sprite[4], (sfVector2f){640, 60});
    sfSprite_setScale(menu->menu_sprite[4], (sfVector2f){1.3, 1.3});
    menu->move_stars = 0;
}
