/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** verif_id.c
*/

#include "../../include/corewar.h"

int verif_id(champion_t *champion)
{
    champion_t *tmp = champion;
    int tab[4];
    int i;

    for (i = 0; i < 4; i++)
        tab[i] = -1;
    i = 0;
    for (; tmp != NULL; tmp = tmp->next) {
        tab[i] = tmp->id;
        i++;
    }
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j && tab[i] == tab[j] && tab[i] != -1)
                return 84;
        }
    }
    return 0;
}