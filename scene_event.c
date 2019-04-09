/*
** EPITECH PROJECT, 2018
** event
** File description:
** defender game event
*/

#include "include/my.h"

int menu_event(sfRenderWindow *window, m_t *m, sfEvent event, int stat)
{
    for (int i = 1; i != 4; i++)
        m->menu->menu_rect[i] = get_rect(window, m->menu->menu_sprite[i]);
    if (event.type == sfEvtMouseButtonReleased) {
        sfMusic_stop(m->menu->clicksound);
        sfMusic_play(m->menu->clicksound);
    }
    for (int i = 1; i != 4; i++) {
        if (sfFloatRect_contains(&m->menu->menu_rect[i], m->menu->pos_mous.x,
        m->menu->pos_mous.y)) {
            sfSprite_setScale(m->menu->menu_sprite[i],
            (sfVector2f){1.04, 1.04});
            stat = menu_event_click(event, i, stat);
        } else
            sfSprite_setScale(m->menu->menu_sprite[i], (sfVector2f){1, 1});
    }
    return (stat);
}

int pause_event(sfRenderWindow *window, m_t *m, sfEvent event, int stat)
{
    for (int i = 0; i != 3; i++)
        m->pause->pause_rect[i] = get_rect(window, m->pause->pause_sprite[i]);
    if (event.type == sfEvtMouseButtonReleased) {
        sfMusic_stop(m->pause->clicksound);
        sfMusic_play(m->pause->clicksound);
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape) {
        stat = 2;
        for (int a = 0; a != 5; a++)
            sfClock_restart(m->game->clock[a]);
    }
    for (int i = 0; i != 3; i++) {
        if (sfFloatRect_contains(&m->pause->pause_rect[i],
        m->pause->pos_mous.x, m->pause->pos_mous.y)) {
            sfSprite_setScale(m->pause->pause_sprite[i],
            (sfVector2f){1.04, 1.04});
            stat = pause_event_click(m->game, event, i, stat);
        } else
            sfSprite_setScale(m->pause->pause_sprite[i], (sfVector2f){1, 1});
    }
    return (stat);
}

int choice_event(sfRenderWindow *window, m_t *m, sfEvent event, int stat)
{
    for (int i = 0; i != 3; i++)
        m->choice->choice_rect[i] =
        get_rect(window, m->choice->choice_sprite[i]);
    if (event.type == sfEvtMouseButtonReleased) {
        sfMusic_stop(m->choice->clicksound);
        sfMusic_play(m->choice->clicksound);
    }
    for (int i = 0; i != 3; i++) {
        if (sfFloatRect_contains(&m->choice->choice_rect[i],
        m->choice->pos_mous.x, m->choice->pos_mous.y)) {
            sfSprite_setScale(m->choice->choice_sprite[i],
            (sfVector2f){1.04, 1.04});
            stat = choice_event_click(m->game, event, i, stat);
        } else
            sfSprite_setScale(m->choice->choice_sprite[i], (sfVector2f){1, 1});
    }
    return (stat);
}

int help_event(sfRenderWindow *window, help_t *help, sfEvent event, int stat)
{
    help->help_rect = get_rect(window, help->help_sprite);
    if (event.type == sfEvtMouseButtonReleased) {
        sfMusic_stop(help->clicksound);
        sfMusic_play(help->clicksound);
    }
    if (sfFloatRect_contains(&help->help_rect, help->pos_mous.x,
    help->pos_mous.y)) {
        sfSprite_setScale(help->help_sprite, (sfVector2f){1.04, 1.04});
        if (event.type == sfEvtMouseButtonReleased)
            stat = 0;
    } else
        sfSprite_setScale(help->help_sprite, (sfVector2f){1, 1});
    return (stat);
}
