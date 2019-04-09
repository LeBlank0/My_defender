/*
** EPITECH PROJECT, 2018
** my_rpg_2018
** File description:
** my_rpg.h
*/

#ifndef RPG_H_
#define RPG_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #define GAME_SCENE m->game->scene
    #define TX_INTRO m->intro->texture
    #define SP_INTRO m->intro->sprite
    #define TX_MENU_INTRO m->menu_intro->texture
    #define SP_MENU_INTRO m->menu_intro->sprite
    #define TX_COMBAT m->combat->texture
    #define SP_COMBAT m->combat->sprite
    #define R_COMBAT m->combat->rect
    #define NB_SP_COMBAT 5
    #define NB_SP_INTRO 2
    #define NB_SP_MENU_INTRO 1
    #define INTRO_SC m->intro->i
    #define TIME m->game->sec
    #define WINDOW m->game->window

    typedef struct game_s {
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        int scene;
        float sec;
    } game_t;

    typedef struct menu_intro_s {
        sfIntRect rect;
        sfTexture **texture;
        sfSprite **sprite;
    } menu_intro_t;

    typedef struct intro_s {
        sfIntRect rect;
        sfMusic *song;
        sfTexture **texture;
        sfSprite **sprite;
        bool i;
    } intro_t;

    typedef struct my_game_s {
        sfTexture *map_texture;
        sfSprite *map_sprite;
        sfIntRect rect_map;
        sfTexture *sacha_texture;
        sfSprite *sacha_sprite;
        sfIntRect rect_sacha;
    } my_game_t;

    typedef struct combat_s {
        sfIntRect *rect;
        sfTexture **texture;
        sfSprite **sprite;
    } combat_t;

    typedef struct main_s {
        game_t *game;
        intro_t *intro;
        menu_intro_t *menu_intro;
        my_game_t *my_game;
        combat_t *combat;
    } main_t;

    /*******************************tireth.c***********************************/
    void tiret_h(void);
    /*******************************audio.c************************************/
    void music_intro(main_t *m);
    /*******************************alloc.c************************************/
    void rpg_malloc(main_t *m);
    /******************************game_loop.c*********************************/
    int game_loop(main_t *m);
    /*********************************init.c***********************************/
    void init_my_var(main_t *m);
    void init_variable_game_base(main_t *m); // initgame__base.c
    /*********************************intro.c**********************************/
    int intro_emerald(main_t *m);
    /******************************menu_intro.c********************************/
    int menu_intro(main_t *m);
    /********************************event.c***********************************/
    void event_game(main_t *m);
    /********************************game.c************************************/
    int game_play(main_t *m);
    /********************************combat.c**********************************/
    int combat_nature(main_t *m);

#endif /* RPG_H_ */
