/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** main_loop.c
*/

#include "../include/corewar.h"

static void handle_cycle(corewar_t *corewar)
{
    corewar->total_cycle++;
}

static int check_end(corewar_t *corewar)
{
    if (corewar->dump != -1 && corewar->total_cycle == corewar->dump) {
        return 1;
    }
}

void launch_corewar(corewar_t *corewar)
{

    while (1) {
        for (int i = 0; i < corewar->nb_champion; i++)
            purchase_execution(corewar, corewar->champion[i]);
        handle_cycle(corewar);
        if (check_end(corewar) == 1) {
            break;
        }
    }
    if (corewar->dump != -1)
        display_memory(corewar->memory, MEM_SIZE);
    return 0;
}