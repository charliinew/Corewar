/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** int_to_bin.c
*/

#include "../include/corewar.h"

char *int_to_bin(int nb)
{
    char *rep = malloc(sizeof(char) * 9);

    for (int i = 0; i < 8; i++)
        rep[i] = '0';
    for (int i = 7; nb > 0; i--) {
        rep[i] = (nb % 2 == 0) ? '0' : '1';
        nb = nb / 2;
    }
    return rep;
}
