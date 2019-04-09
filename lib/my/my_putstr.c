/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** string
*/

#include "../../include/my.h"

void my_putstr(char const *str)
{
    int w = 0;

    while (str[w] != '\0') {
        my_putchar(str[w]);
        w++;
    }
}
