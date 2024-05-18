/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main_loop.c
*/

#include "../../include/corewar.h"


void verif_player_is_alive(corewar_t *corewar)
{
    champion_t *tmp = *corewar->champion;

    for (; tmp != NULL; tmp = tmp->next) {
        if ((*corewar->champion)->live != -1)
            purshase_execution(corewar, tmp);
    }
}

void launch_corewar(corewar_t *corewar)
{
    while (1) {
        verif_player_is_alive(corewar);
        if (check_end(corewar) == 1) {
            display_winner_player(corewar);
            break;
        }
    }
    if (corewar->dump != -1)
        display_memory(corewar->memory, MEM_SIZE);
}
