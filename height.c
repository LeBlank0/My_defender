/*
** EPITECH PROJECT, 2018
** set
** File description:
** defender game set
*/

#include "include/my.h"

int height(char **map)
{
    int a = 0;

    for (int i = 0; map[i][0] != '1'; i++) {
        a += 50;
    }
    a += 75;
    return (a);
}
