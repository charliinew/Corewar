/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main_loop.c
*/

#include "../include/corewar.h"

static int alive_champion(corewar_t *corewar)
{
    int i = 0;
    int counter = 0;

    for (; i < corewar->nb_champion; i++) {
        if (corewar->champion[i]->live > 0)
            counter++;
        corewar->champion[i]->live = 0;
    }
    if (counter <= 1)
        return 1;
    return 0;
}

static int check_end(corewar_t *corewar)
{
    corewar->total_cycle++;
    corewar->actual_ctd++;
    if (corewar->dump != -1 && corewar->total_cycle >= corewar->dump)
        return 1;
    if (corewar->nb_live >= NBR_LIVE) {
        corewar->nb_live = corewar->nb_live % NBR_LIVE;
        corewar->max_ctd -= CYCLE_DELTA;
    }
    if (corewar->actual_ctd >= corewar->max_ctd) {
        corewar->actual_ctd = corewar->actual_ctd % corewar->max_ctd;
        return alive_champion(corewar);
    }
    return 0;
}

void launch_corewar(corewar_t *corewar)
{
    while (1) {
        for (int i = 0; i < corewar->nb_champion; i++)
            purshase_execution(corewar, corewar->champion[i]);
        if (check_end(corewar) == 1) {
            break;
        }
    }
    if (corewar->dump != -1)
        display_memory(corewar->memory, MEM_SIZE);
}
