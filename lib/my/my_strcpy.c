/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** cpy
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int w = 0;

    while (src[w] != '\0') {
        dest[w] = src[w];
        w++;
    }
    return (dest);
}
