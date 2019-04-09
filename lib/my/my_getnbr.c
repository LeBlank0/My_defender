/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** getnbr
*/

#include "../../include/my.h"

int my_getnbr(char *str)
{
    int i = 0;
    int n = 0;
    int neg = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg++;
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            n = (n + str[i] - '0') * 10;
            i++;
        }
        else
            break;
    }
    if (neg > 0 && neg % 2 == 0)
        return ((-1 * n) / 10);
    else
        return (n / 10);
}
