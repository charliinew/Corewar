/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_zjmp.c
*/

#include "../../include/corewar.h"

void my_zjmp(corewar_t *corewar, champion_t *champion)
{
    int value;

    champion->cycle_instruction = 19;
    if (champion->carry == 1) {
        value = reconstruct_int(corewar->memory, champion->PC + 1, 2);
        champion->PC = (champion->PC + value % IDX_MOD) % MEM_SIZE;
    } else
        champion->PC = (champion->PC + 3) % MEM_SIZE;
}
