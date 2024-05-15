/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** qzd
*/

#include <stdio.h>
#include "../include/lib.h"

int valeur_ext(int nombre)
{
    int valeur_max = 2147483647;
    int valeur_min = -2147483648;

    if (nombre < (valeur_max / 10) && nombre > (valeur_min / 10)) {
        return (nombre);
    } else if (nombre < (valeur_min / 10))
        return (-13830);
    else
        return (13830);
}

int nbr_signe(int signe, int nombre)
{
    if (signe == '-') {
        nombre = -1 * nombre;
        return (nombre);
    }
    return (nombre);
}

long my_getnbr(char const *str)
{
    int i = 0;
    int nombre = 0;
    int signe = '+';

    if (str != 0 && str[0] == '-') {
        signe = '-';
        i++;
    }
    while (str != 0 && str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            break;
        if (str[i] >= '0' && str[i] <= '9')
            nombre = nbre(i, nombre, str);
        i++;
    }
    nombre = nbr_signe(signe, nombre);
    return (nombre);
}
