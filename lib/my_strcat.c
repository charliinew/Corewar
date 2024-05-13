/*
** EPITECH PROJECT, 2023
** MY_STRCAT
** File description:
** join 2 str
*/

#include "../include/include.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int u = 0;

    while (dest[i] != '\0') {
        i ++;
    }
    while (src[u] != '\0') {
        dest[i] = src[u];
        u++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
