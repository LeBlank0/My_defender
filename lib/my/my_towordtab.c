/*
** EPITECH PROJECT, 2018
** my_towordtab
** File description:
** change a char* into a char**
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char **towordtotab(char *buffer, int x, int y, char z)
{
    int a = 0;
    int b = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (y + 1));
    for (int i = 0; buffer[i]; i++, a++) {
        tab[a] = malloc(sizeof(char) * (x + 1));
        for (; buffer[i] != z && buffer[i] != '\0'; i++, b++)
            tab[a][b] = buffer[i];
        if (buffer[i] == '\0')
            i -= 1;
        tab[a][b + 1] = '\0';
        b = 0;
    }
    tab[a] = NULL;
    return (tab);
}

char **my_towordtab(char *buffer, char a)
{
    int x = 0;
    int y = 0;
    int tmp = 0;
    int i = 0;
    char **tab = NULL;

    for (y = 1; buffer[i] != '\0'; i++, tmp++)
        if (buffer[i] == a) {
            y++;
            x = x < tmp ? tmp : x;
            tmp = 0;
        }
    tab = towordtotab(buffer, x, y, a);
    return (tab);
}
