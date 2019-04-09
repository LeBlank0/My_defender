/*
** EPITECH PROJECT, 2019
** my_itoa
** File description:
** int to array
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_itoa(int nb)
{
    char *dest = 0;
    int pos = 0;

    dest = malloc(sizeof(char) *(12));
    if (nb < 0) {
        nb *= -1;
        dest[pos] = '-';
        pos++;
    }
    while (nb > 9) {
        dest[pos] = nb % 10 + '0';
        nb /= 10;
        pos++;
    }
    dest[pos] = nb + '0';
    dest[pos + 1] = '\0';
    my_revstr(dest);
    return (dest);
}
