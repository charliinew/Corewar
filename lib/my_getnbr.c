/*
** EPITECH PROJECT, 2023
** MY_GETNBR
** File description:
** get nbr
*/

#include "../include/lib.h"

int define_signe(char const *pop)
{
    int nb_signe = 0;
    int avc = 0;

    while (pop[avc] != '\0' && (pop[avc] < 48 || pop[avc] > 57)) {
        if (pop[avc] == 45) {
            nb_signe ++;
        }
        avc++;
    }
    if (nb_signe % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}

int my_getnbr(char const *str)
{
    int signe = 0;
    int decal = 0;
    int result = 0;

    signe = define_signe(str);
    while (str[decal] < 48 || str[decal] > 57) {
        decal ++;
    }
    while (str[decal] >= 48 && str[decal] <= 57) {
        result = (result * 10) + str[decal] - 48;
        decal ++;
    }
    result = result * signe;
    return result;
}
