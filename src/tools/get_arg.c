/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** get_arg.c
*/

#include "../../include/corewar.h"

int get_arg(corewar_t *corewar, int *index, int size)
{
    int arg = reconstruct_int(corewar->memory, *index, size);

    *index = (*index + size) % MEM_SIZE;
    return arg;
}
