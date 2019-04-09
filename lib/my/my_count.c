/*
** EPITECH PROJECT, 2018
** my_count
** File description:
** count
*/

#include "../../include/my.h"

int my_count(char **str, char a, int b, int c)
{
    int nb = 0;

    for (int i = 0; i != b; i++)
        for (int y = 0; y != c; y++)
            nb += (str[i][y] == a);
    return (nb);
}
