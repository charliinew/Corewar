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
        if (tmp->live > 0) {
            counter++;
            tmp->live = 0;
        } else {
            tmp->live = -1;
        }
    }
    if (counter <= 1)
        return 1;
    return 0;
}

static void clear_child_fork(champion_t *tmp)
{
    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->live <= 0) {
            free_champ(*tmp->child);
            tmp->child = NULL;
        }
        if (tmp->child != NULL)
            clear_child_fork(*tmp->child);
    }
}

int check_end(corewar_t *corewar)
{
    champion_t *champion = *corewar->champion;

    corewar->total_cycle++;
    corewar->actual_ctd++;
    if (corewar->dump != -1 && corewar->total_cycle > corewar->dump)
        return 1;
    if (corewar->nb_live >= NBR_LIVE) {
        corewar->nb_live = corewar->nb_live % NBR_LIVE;
        corewar->max_ctd -= CYCLE_DELTA;
    }
    if (corewar->actual_ctd >= corewar->max_ctd) {
        corewar->actual_ctd = corewar->actual_ctd % corewar->max_ctd;
        clear_child_fork(champion);
        return alive_champion(corewar);
    }
    return 0;
}
