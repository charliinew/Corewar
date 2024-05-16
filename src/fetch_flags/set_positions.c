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

    for (int i = 0; i < corewar->nb_champion; i++) {
        if (corewar->champion[i]->flags->a == -1) {
            corewar->champion[i]->flags->a = pos;
            pos += augment;
        }
    }
}
