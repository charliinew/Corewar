/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_positions.c
*/

#include "../../include/corewar.h"

void set_position(corewar_t *corewar)
{
    int pos = 0;
    int augment = MEM_SIZE / corewar->nb_champion;
    champion_t  *tmp = *corewar->champion;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->flags->a == -1) {
            tmp->flags->a = pos;
            pos += augment;
        }
    }
}
