/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_end_loop.c
*/

#include "../../include/corewar.h"

static int alive_champion(corewar_t *corewar)
{
    int counter = 0;
    champion_t *tmp = *corewar->champion;

    for (; tmp != NULL; tmp = tmp->next) {
        if ((*corewar->champion)->live > 0) {
            counter++;
            (*corewar->champion)->live = 0;
        } else
            (*corewar->champion)->live = -1;
    }
    if (counter <= 1)
        return 1;
    return 0;
}

int check_end(corewar_t *corewar)
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
