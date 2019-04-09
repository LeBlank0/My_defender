/*
** EPITECH PROJECT, 2018
** rect
** File description:
** defender game rect
*/

#include "include/my.h"

sfFloatRect get_rect(sfRenderWindow *window, sfSprite *sprite)
{
    sfFloatRect rect;

    rect.left = (((sfSprite_getGlobalBounds(sprite)).left
    / 1920.0) * (sfRenderWindow_getSize(window)).x);
    rect.width = (((sfSprite_getGlobalBounds(sprite)).width
    / 1920.0) * (sfRenderWindow_getSize(window)).x);
    rect.top = (((sfSprite_getGlobalBounds(sprite)).top
    / 1050.0) * (sfRenderWindow_getSize(window)).y);
    rect.height = (((sfSprite_getGlobalBounds(sprite)).height
    / 1050.0) * (sfRenderWindow_getSize(window)).y);
    return (rect);
}
