/*
** EPITECH PROJECT, 2018
** my_strncpy
** File description:
** cpy
*/

#include "../../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int w = 0;

    while (w < n) {
        dest[w] = src[w];
        w++;
    }
    if (n > dest[w]) {
        dest[w] = '\0';
    }
    return (dest);
}
