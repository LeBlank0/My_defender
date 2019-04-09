/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** struct
*/

#ifndef LISTE_H_
#define LISTE_H_

#define TR 20
#define MOB 50
#define MH 19
#define MW 36

typedef struct menu_s
{
    sfMusic *space;
    sfMusic *clicksound;
    sfTexture **menu_text;
    sfSprite **menu_sprite;
    sfClock *clock_stars;
    sfVector2i pos_mous;
    sfFloatRect *menu_rect;
    int move_stars;
} menu_t;

typedef struct help_s
{
    sfMusic *clicksound;
    sfTexture *help_text;
    sfSprite *help_sprite;
    sfVector2i pos_mous;
    sfFloatRect help_rect;
    sfFont *font;
    sfText **text;
} help_t;

typedef struct pause_s
{
    sfMusic *clicksound;
    sfTexture *pause_text;
    sfSprite **pause_sprite;
    sfVector2i pos_mous;
    sfFloatRect *pause_rect;
} pause_t;

typedef struct end_s
{
    sfClock *clock;
    sfFont *font;
    sfText *text;
    sfTexture *end_text;
    sfSprite *end_sprite;
} end_t;

typedef struct choice_s
{
    sfMusic *clicksound;
    sfTexture *choice_text;
    sfSprite **choice_sprite;
    sfVector2i pos_mous;
    sfFloatRect *choice_rect;
} choice_t;

typedef struct game_road_s
{
    int nbr;
    int nbb;
    sfTexture *road_text;
    sfSprite **road_sprite;
    sfFloatRect *road_rect;
} game_road_t;

typedef struct game_back_s
{
    sfTexture *back_text;
    sfSprite **back_sprite;
    sfFloatRect *back_rect;
} game_back_t;

typedef struct game_home_s
{
    sfTexture *home_text;
    sfSprite **home_sprite;
    sfFloatRect *home_rect;
} game_home_t;

typedef struct game_turret_s
{
    sfFont *font;
    sfText **text;
    sfTexture *turret_text;
    sfSprite **turret_sprite;
    sfFloatRect *turret_rect;
    sfCircleShape **turret_circle;
} game_turret_t;

typedef struct game_mob_s
{
    char *dir;
    sfTexture *mob_text;
    sfSprite **mob_sprite;
    sfFloatRect *mob_rect;
} game_mob_t;

typedef struct game_stat_s
{
    int tnb;
    int coins;
    int score;
    int dstat;
    int cost;
    int mob;
    int dmob;
    int health;
    int hei;
    int *type;
    int *lvl;
    int *mobpv;
    float diff;
    float speed;
    float rd;
    float *pause;
} game_stat_t;

typedef struct game_s
{
    game_road_t *game_road;
    game_back_t *game_back;
    game_home_t *game_home;
    game_turret_t *game_turret;
    game_mob_t *game_mob;
    game_stat_t *game_stat;
    sfClock **clock;
    char **map;
    sfVector2i pos_mous;
} game_t;

typedef struct m_s
{
    menu_t *menu;
    choice_t *choice;
    pause_t *pause;
    help_t *help;
    game_t *game;
    end_t *end;
} m_t;

int height(char **map);
void set(sfRenderWindow *window, m_t *m);
void end_set(end_t *end);
void menu_set(menu_t *menu);
void game_back_set(game_t *game);
void game_road_set(game_t *game);
void help_set(help_t *help);
void choice_set(choice_t *choice);
void pause_set(pause_t *pause);
void game_set(game_t *game, char *str);
void game_map_set(game_t *game);
void game_stat_set(game_t *game);
int road_width(game_t *game, int i, int y);
int road_height(game_t *game, int i, int y);
void game_turret_set(game_t *game);
void text_loop_set(game_t *game);
void parallax(sfRenderWindow *window, menu_t *menu);
sfFloatRect get_rect(sfRenderWindow *window, sfSprite *sprite);
int menu_event_click(sfEvent event, int i, int stat);
int choice_event_click(game_t *game, sfEvent event, int i, int stat);
int pause_event_click(game_t *game, sfEvent event, int i, int stat);
void turret_event_click(game_t *game, sfEvent event, int i);
void turret_event_dstat(sfRenderWindow *window, game_t *game);
void turret_event_rect(sfRenderWindow *window, game_t *game, sfEvent event);
void turret_pos(sfRenderWindow *window, game_t *game);
void turret_pos_r(sfRenderWindow *window, game_t *game, int i, int y);
void turret_pos_r_2(sfRenderWindow *window, game_t *game);
int menu_event(sfRenderWindow *window, m_t *m, sfEvent event, int stat);
int choice_event(sfRenderWindow *window, m_t *m, sfEvent event, int stat);
int pause_event(sfRenderWindow *window, m_t *m, sfEvent event, int stat);
int help_event(sfRenderWindow *window, help_t *help, sfEvent event, int stat);
int game_event(sfRenderWindow *window, game_t *game, sfEvent event, int stat);
void turret_event(sfRenderWindow *window, game_t *game, sfEvent event);
int game(sfRenderWindow *window, game_t *game, end_t *end);
int circle_contains(game_t *game, int a, int b);
void dir(sfRenderWindow *window, game_t *game, int x);
void game_follow_loop(game_t *game, int i);
void mob(sfRenderWindow *window, game_t *game);
void dtime(game_t *game);
void reset(game_t *game);
void mob_killing(sfRenderWindow *window, game_t *game, int i);
void follow(game_t *game, int a, int b);
void attack(game_t *game, int a, int b);
void draw_menu(sfRenderWindow *window, menu_t *menu);
void draw_choice(sfRenderWindow *window, choice_t *choice);
void draw_help(sfRenderWindow *window, help_t *help);
void draw_pause(sfRenderWindow *window, pause_t *pause);
void draw_game(sfRenderWindow *window, game_t *game);
void draw_end(sfRenderWindow *window, end_t *end);
void destroy_choice(choice_t *choice);
void destroy_help(help_t *help);
void destroy_pause(pause_t *pause);
void destroy_game(game_t *game);
void destroy_end(end_t *end);
void destroy_menu(sfRenderWindow *window, menu_t *menu, game_t *game);

#endif
