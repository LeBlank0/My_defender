/*
** EPITECH PROJECT, 2018
** draw
** File description:
** defender game draw
*/

#include "include/my.h"

void draw_end(sfRenderWindow *window, end_t *end)
{
    sfRenderWindow_drawSprite(window, end->end_sprite, NULL);
    sfRenderWindow_drawText(window, end->text, NULL);
}

void draw_menu(sfRenderWindow *window, menu_t *menu)
{
    for (int i = 0; i != (4 + 1); i++)
        sfRenderWindow_drawSprite(window, menu->menu_sprite[i], NULL);
}

void draw_pause(sfRenderWindow *window, pause_t *pause)
{
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawSprite(window, pause->pause_sprite[i], NULL);
}

void draw_choice(sfRenderWindow *window, choice_t *choice)
{
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawSprite(window, choice->choice_sprite[i], NULL);
}

void draw_help(sfRenderWindow *window, help_t *help)
{
    sfRenderWindow_drawSprite(window, help->help_sprite, NULL);
    for (int i = 0; i != 4; i++)
        sfRenderWindow_drawText(window, help->text[i], NULL);
}
