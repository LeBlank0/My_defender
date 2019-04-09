/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** ncat
*/

#include "../../include/my.h"

char *my_strncat(char *one, char const *two, int nb)
{
    int i = my_strlen(one);
    int w = 0;
    char *fin = malloc(sizeof(char) * (i + my_strlen(two) + 1));

    for (int a = 0; one[a] != '\0'; a++)
        fin[a] = one[a];
    while (two[w] != nb) {
        fin[i + w] = two[w];
        w++;
    }
    fin[i + w] = '\0';
    return (fin);
}
