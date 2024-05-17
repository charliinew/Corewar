/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** execution.c
*/

#include "../../include/corewar.h"

void purshase_execution(corewar_t *corewar, champion_t *champion)
{
    int instruction = corewar->memory[champion->PC];
    int i;

    if (champion->cycle_instruction > 0) {
        champion->cycle_instruction--;
        return;
    }
    for (i = 0; i < 16; i++) {
        if (instruction == op_tab[i].code) {
            instr_tab[i](corewar, champion);
            break;
        }
    }
    if (i == 17)
        champion->PC++;
}
