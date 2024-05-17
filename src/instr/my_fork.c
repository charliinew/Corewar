/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-charles.ignoux
** File description:
** my_fork.c
*/

#include "../../include/corewar.h"

void my_fork(corewar_t *corewar, champion_t *champion)
{
    int arg = reconstruct_int(corewar->memory,
        (champion->PC + 1) % MEM_SIZE, 2);
    int child_pc = (champion->PC + arg % IDX_MOD) % MEM_SIZE;

    champion->cycle_instruction = 799;
    add_child(corewar, champion, child_pc, 799);
    return;
}
