/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** free_struct.c
*/

#include "../../include/corewar.h"

void free_struct(corewar_t *corewar, u_int8_t *memory)
{
    for (; *corewar->champion != NULL; *corewar->champion =
            (*corewar->champion)->next) {
        if ((*corewar->champion)->flags->prog_name != NULL)
            free((*corewar->champion)->flags->prog_name);
        free((*corewar->champion)->flags);
        free((*corewar->champion)->header);
    }
    free(*corewar->champion);
    free(memory);
}
