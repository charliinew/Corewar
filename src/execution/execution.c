/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** execution.c
*/

#include "../../include/corewar.h"

void purshase_execution(corewar_t *corewar, champion_t *champion)
{
    int instruction = my_getnbr_doop(corewar->memory[champion->PC]);

    printf("%d\n", instruction);
}