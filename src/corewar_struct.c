/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar_struct.c
*/

#include "../include/corewar.h"

corewar_t *init_corewar_struct(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (corewar == NULL)
        return NULL;
    corewar->dump = -1;
    corewar->nb_champion = 0;
    corewar->max_ctd = CYCLE_TO_DIE;
    corewar->actual_ctd = 0;
    corewar->total_cycle = 0;
    corewar->nb_live = 0;
    corewar->memory = init_memory();
    if (corewar->memory == NULL) {
        free(corewar);
        return NULL;
    }
    for (int i = 0; i < 4; i++)
        corewar->champion[i] = NULL;
    return corewar;
}
