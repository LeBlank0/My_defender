/*
** EPITECH PROJECT, 2018
** my_defender
** File description:
** defender main
*/

#include "include/my.h"

int event_loop(sfRenderWindow *window, sfEvent event, m_t *m, int stat)
{
    if (stat == 2)
        stat = game_event(window, m->game, event, stat);
    else if (stat == 3)
        stat = pause_event(window, m, event, stat);
    else if (stat == 4)
        stat = choice_event(window, m, event, stat);
    return (stat);
}

int event(sfRenderWindow *window, m_t *m, int stat)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        m->menu->pos_mous = sfMouse_getPositionRenderWindow(window);
        m->choice->pos_mous = sfMouse_getPositionRenderWindow(window);
        m->help->pos_mous = sfMouse_getPositionRenderWindow(window);
        m->game->pos_mous = sfMouse_getPositionRenderWindow(window);
        m->pause->pos_mous = sfMouse_getPositionRenderWindow(window);
        if (event.type == sfEvtClosed || (event.type == sfEvtKeyReleased
        && event.key.code == sfKeyEscape && stat != 2 && stat != 3))
            stat = 84;
        if (stat == 0)
            stat = menu_event(window, m, event, stat);
        else if (stat == 1)
            stat = help_event(window, m->help, event, stat);
        else
            stat = event_loop(window, event, m, stat);
    }
    return (stat);
}

int loop2(sfRenderWindow *window, m_t *m, int stat)
{
    if (stat == 3) {
        draw_game(window, m->game);
        draw_pause(window, m->pause);
        stat = event(window, m, stat);
    }
    if (stat == 4) {
        parallax(window, m->menu);
        draw_choice(window, m->choice);
        stat = event(window, m, stat);
    }
    if (stat == 5) {
        draw_game(window, m->game);
        draw_end(window, m->end);
        if ((sfTime_asSeconds(sfClock_getElapsedTime(m->end->clock))) > 8)
            stat = 0;
    }
    sfRenderWindow_display(window);
    return (stat);
}

int loop1(sfRenderWindow *window, m_t *m, int stat)
{
    sfRenderWindow_clear(window, sfBlack);
    if (stat == 0) {
        parallax(window, m->menu);
        draw_menu(window, m->menu);
        stat = event(window, m, stat);
    }
    if (stat == 1) {
        parallax(window, m->menu);
        draw_help(window, m->help);
        stat = event(window, m, stat);
    }
    if (stat == 2) {
        stat = game(window, m->game, m->end);
        draw_game(window, m->game);
        stat = event(window, m, stat);
    }
    return (stat);
}

int main(void)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode)
    {1920, 1080, 32}, "Moon Defender", sfResize | sfClose, NULL);
    int stat = 0;
    m_t *m = malloc(sizeof(*m));

    set(window, m);
    sfMusic_play(m->menu->space);
    sfMusic_setLoop(m->menu->space, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        stat = loop1(window, m, stat);
        stat = loop2(window, m, stat);
        if (stat == 84)
            break;
    }
    destroy_choice(m->choice);
    destroy_help(m->help);
    destroy_pause(m->pause);
    destroy_menu(window, m->menu, m->game);
    destroy_game(m->game);
    destroy_end(m->end);
    return (0);
}
