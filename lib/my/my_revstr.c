/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** str
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int w = 0;
    int i = w;
    char x;

    while (str[w] != '\0') {
        w++;
    }
    w--;
    while (w > i) {
        x = str[i];
        str[i] = str[w];
        str[w] = x;
        i++;
        w--;
    }
    return (str);
}
