/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** cmp
*/

#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int y)
{
    for (int i = 0; i != y; i++)
        if (s1[i] != s2[i])
            return (1);
    return (0);
}
