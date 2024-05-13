/*
** EPITECH PROJECT, 2023
** MY_STRDUP
** File description:
** return str in malloc
*/

#include <stdlib.h>
#include "../include/include.h"
char *my_strdup(char const *src)
{
    int i = 0;
    char *tab;

    tab = malloc(my_strlen(src) + 1);
    while (src[i] != '\0') {
        tab[i] = src[i];
        i ++;
    }
    tab[i] = '\0';
    return (tab);
}
