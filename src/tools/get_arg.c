/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** get_arg.c
*/

#include "../../include/corewar.h"

int get_arg(corewar_t *corewar, champion_t *champion, int size)
{
    int arg = reconstruct_int(corewar->memory, champion->PC, size);

    champion->PC = (champion->PC + size) % MEM_SIZE;
    return arg;
}
