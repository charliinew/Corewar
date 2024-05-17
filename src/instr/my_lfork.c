/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_lfork.c
*/

#include "../../include/corewar.h"

void my_lfork(corewar_t *corewar, champion_t *champion)
{
    int arg = reconstruct_int(corewar->memory,
        (champion->PC + 1) % MEM_SIZE, 2);
    int child_pc = (champion->PC + arg) % MEM_SIZE;

    champion->cycle_instruction = 999;
    add_child(corewar, champion, child_pc, 999);
    return;
}
