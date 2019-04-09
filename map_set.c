/*
** EPITECH PROJECT, 2018
** map_set
** File description:
** defender map set
*/

#include "include/my.h"

int rd(void)
{
    int a = 0;

    a = rand() % 100;
    if (a <= 2)
        return (50);
    if (a >= 98)
        return (100);
    if (a > 2 && a <= 5)
        return (150);
    return (0);
}

void case2(game_t *game, int i, int y)
{
    sfSprite_setPosition(game->game_road->road_sprite
    [game->game_road->nbr], (sfVector2f){(y * 50), (i * 50)});
    game->game_road->road_rect[game->game_road->nbr] = ((sfFloatRect)
    {road_height(game, i, y), road_width(game, i, y), 50, 50});
    sfSprite_setTextureRect(game->game_road->road_sprite
    [game->game_road->nbr], (sfIntRect)
    {(game->game_road->road_rect[game->game_road->nbr]).top,
    (game->game_road->road_rect[game->game_road->nbr]).left,
    (game->game_road->road_rect[game->game_road->nbr]).height,
    (game->game_road->road_rect[game->game_road->nbr]).width});
    game->game_road->nbr += 1;
}

void case1(game_t *game, int i, int y)
{
    int rad = 0;

    if (game->map[i][y] == '0') {
        sfSprite_setPosition(game->game_back->back_sprite
        [game->game_road->nbb], (sfVector2f){(y * 50), (i * 50)});
        rad = rd();
        game->game_back->back_rect[game->game_road->nbb] = ((sfFloatRect)
        {0, rad, 50, 50});
        sfSprite_setTextureRect(game->game_back->back_sprite
        [game->game_road->nbb],
        (sfIntRect){(game->game_back->back_rect[game->game_road->nbb]).top,
        (game->game_back->back_rect[game->game_road->nbb]).left,
        (game->game_back->back_rect[game->game_road->nbb]).height,
        (game->game_back->back_rect[game->game_road->nbb]).width});
        game->game_road->nbb += 1;
    } else if (game->map[i][y] == '1')
        case2(game, i, y);
}

void home_set(game_t *game)
{
    int a = 0;

    for (; game->map[a][MW - 1] != '1'; a++);
    sfSprite_setPosition(game->game_home->home_sprite[0],
    (sfVector2f){1800, 0});
    sfSprite_setPosition(game->game_home->home_sprite[1],
    (sfVector2f){1800, (((a + 1) * 50) - 3)});
    game->game_home->home_rect[0] = ((sfFloatRect){0, 0, 950, 120});
    sfSprite_setTextureRect(game->game_home->home_sprite[0],
    (sfIntRect){(game->game_home->home_rect[0]).top,
    (game->game_home->home_rect[0]).left,
    (game->game_home->home_rect[0]).height,
    (game->game_home->home_rect[0]).width});
    game->game_home->home_rect[1] = ((sfFloatRect){950, 0, 100, 30});
    sfSprite_setTextureRect(game->game_home->home_sprite[1],
    (sfIntRect){(game->game_home->home_rect[1]).top,
    (game->game_home->home_rect[1]).left,
    (game->game_home->home_rect[1]).height,
    (game->game_home->home_rect[1]).width});
}

void game_map_set(game_t *game)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned seed;

    read(fd, &seed, sizeof seed);
    srand(seed);
    close(fd);
    for (int i = 0; i != MH; i++)
        for (int y = 0; y != MW; y++)
            case1(game, i, y);
    home_set(game);
}
