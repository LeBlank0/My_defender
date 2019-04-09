/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** nbr
*/

#include "../../include/my.h"

void my_put_nbr(int nb)
{
    int div = 1;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / div) >= 10)
        div *= 10;
    while (div > 0) {
        my_putchar((nb / div) % 10 + '0');
        div /= 10;
    }
}
