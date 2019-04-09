/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** cat
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strcat(char *one, char *two)
{
    int i = my_strlen(one);
    int w = 0;
    char *fin = malloc(sizeof(char) * (i + my_strlen(two) + 1));

    for (int a = 0; one[a] != '\0'; a++)
        fin[a] = one[a];
    while (two[w] != '\0') {
        fin[i + w] = two[w];
        w++;
    }
    fin[i + w] = '\0';
    return (fin);
}
