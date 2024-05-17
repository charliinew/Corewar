/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** parsing.c
*/

#include "../../include/corewar.h"

int parsing(champion_t **champion, corewar_t *corewar)
{
    champion_t *tmp = *champion;

    for (; tmp != NULL; tmp = tmp->next) {
        if (verif_open(tmp, corewar->memory) == 84)
            return 84;
    }
    if (verif_id(*champion) == 84)
        return 84;
    return 0;
}
