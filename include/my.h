/*
** EPITECH PROJECT, 2018
** my
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Network.h>
#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

char **my_towordtab(char *buffer, char a);

char *get_file(char *str);

int my_count(char **str, char a, int b, int c);

char *my_itoa(int nb);

int my_getnbr(char *str);

void my_putchar(char c);

void my_put_nbr(int nb);

void my_putstr(char const *str);

char *my_revstr(char *str);

char *my_strcat(char *one, char *two);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

int my_strncmp(char const *s1, char const *s2, int y);

char *my_strncat(char *dest, char const *src, int nb);

char *my_strdup(char const *src);

#endif
