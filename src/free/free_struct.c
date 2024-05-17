/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** free_struct.c
*/

#include "../../include/corewar.h"

void free_struct(corewar_t *corewar, u_int8_t *memory)
{
    free(corewar);
    free(memory);
}
