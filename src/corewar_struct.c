/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar_struct.c
*/

#include "../include/corewar.h"

void init_corewar_struct(corewar_t *corewar, champion_t **champion)
{
    corewar->dump = -1;
    corewar->nb_champion = 0;
    corewar->max_ctd = CYCLE_TO_DIE;
    corewar->actual_ctd = 0;
    corewar->total_cycle = 0;
    corewar->nb_live = 0;
    corewar->champion = champion;
    corewar->memory = init_memory();
}
