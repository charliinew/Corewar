/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_champion.c
*/

#include "../../include/corewar.h"

champion_t *set_champion(void)
{
    champion_t *champion = malloc(sizeof(champion_t));

    if (champion == NULL)
        return NULL;
    champion->flags = malloc(sizeof(flags_t));
    champion->header = NULL;
    if (champion->flags == NULL) {
        free(champion);
        return NULL;
    }
    champion->flags->n = -1;
    champion->flags->a = -1;
    champion->flags->prog_name = NULL;
    return champion;
}
