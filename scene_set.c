/*
** EPITECH PROJECT, 2018
** set
** File description:
** defender game set
*/

#include "include/my.h"

char const *TEXTH[4] =
{"Game controles :",
    "Drag and drop turret to protect your base against wave of ennemies !",
    "But be carefull ennemies are getting stonger and faster each wave.",
    "WARNING the turrets are 2 blocks wide and cannot be placed on the road."};

void pause_set(pause_t *pause)
{
    pause->clicksound = sfMusic_createFromFile("sprite/click.ogg");
    pause->pause_sprite = malloc(sizeof(sfSprite*) * 3);
    pause->pause_rect = malloc(sizeof(sfFloatRect) * 3);
    pause->pause_text = sfTexture_createFromFile("sprite/button.png", NULL);
    for (int i = 0; i != 3; i++) {
        pause->pause_sprite[i] = sfSprite_create();
        sfSprite_setTexture(pause->pause_sprite[i], pause->pause_text, sfTrue);
        sfSprite_setPosition(pause->pause_sprite[i], (sfVector2f){760,
        (280 + (i * 200))});
        sfSprite_setColor(pause->pause_sprite[i], sfColor_fromRGBA
        (255, 255, 255, 150));
        pause->pause_rect[i] = (sfFloatRect){i * 116, 0, 116, 387};
        sfSprite_setTextureRect(pause->pause_sprite[i],
        (sfIntRect){(pause->pause_rect[i]).top, (pause->pause_rect[i]).left,
        (pause->pause_rect[i]).height, (pause->pause_rect[i]).width});
    }
}

void choice_set(choice_t *choice)
{
    choice->clicksound = sfMusic_createFromFile("sprite/click.ogg");
    choice->choice_sprite = malloc(sizeof(sfSprite*) * 3);
    choice->choice_rect = malloc(sizeof(sfFloatRect) * 3);
    choice->choice_text = sfTexture_createFromFile("sprite/button.png", NULL);
    for (int i = 0; i != 3; i++) {
        choice->choice_sprite[i] = sfSprite_create();
        sfSprite_setTexture(choice->choice_sprite[i]
        , choice->choice_text, sfTrue);
        sfSprite_setPosition(choice->choice_sprite[i], (sfVector2f){760,
        (280 + (i * 200))});
        choice->choice_rect[i] = (sfFloatRect)
        {(232 - (i * 116)), 774, 116, 387};
        sfSprite_setTextureRect(choice->choice_sprite[i], (sfIntRect)
        {(choice->choice_rect[i]).top, (choice->choice_rect[i]).left,
        (choice->choice_rect[i]).height, (choice->choice_rect[i]).width});
    }
}

void help_loop_set(help_t *help)
{
    for (int i = 0; i != 4; i++) {
        help->text[i] = sfText_create();
        sfText_setFont(help->text[i], help->font);
        sfText_setPosition(help->text[i],
        (sfVector2f){100, (150 + (100 * i))});
        sfText_setCharacterSize(help->text[i], 100);
        sfText_setString(help->text[i], TEXTH[i]);
        if (i == 0) {
            sfText_setCharacterSize(help->text[i], 200);
            sfText_setPosition(help->text[i],
            (sfVector2f){100, (20 + (100 * i))});
        }
        if (i == 3)
            sfText_setPosition(help->text[i],
            (sfVector2f){100, 600});
    }
}

void help_set(help_t *help)
{
    help->help_text = sfTexture_createFromFile("sprite/button.png", NULL);
    help->clicksound = sfMusic_createFromFile("sprite/click.ogg");
    help->help_sprite = sfSprite_create();
    sfSprite_setTexture(help->help_sprite, help->help_text, sfTrue);
    sfSprite_setPosition(help->help_sprite, (sfVector2f){760, 860});
    help->help_rect = (sfFloatRect){116, 0, 116, 387};
    sfSprite_setTextureRect(help->help_sprite,
    (sfIntRect){(help->help_rect).top, (help->help_rect).left,
    (help->help_rect).height, (help->help_rect).width});
    help->help_rect = sfSprite_getGlobalBounds(help->help_sprite);
    help->text = malloc(sizeof(sfText*) * 4);
    help->font = sfFont_createFromFile("sprite/space.ttf");
    help_loop_set(help);
}

void end_set(end_t *end)
{
    end->clock = sfClock_create();
    end->end_text = sfTexture_createFromFile("sprite/end.png", NULL);
    end->end_sprite = sfSprite_create();
    sfSprite_setTexture(end->end_sprite, end->end_text, sfTrue);
    sfSprite_setPosition(end->end_sprite, (sfVector2f){650, 225});
    end->font = sfFont_createFromFile("sprite/space.ttf");
    end->text = sfText_create();
    sfText_setFont(end->text, end->font);
    sfText_setPosition(end->text, (sfVector2f){850, 350});
    sfText_setCharacterSize(end->text, 100);
}
