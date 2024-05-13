/*
** EPITECH PROJECT, 2023
** LL
** File description:
** ML
*/

#include "../include/lib.h"
#include "../include/lib.h"

int my_strlen(char const *str)
{
    int occ = 0;

    while (str[occ] != '\0') {
        occ ++;
    }
    return occ;
}
