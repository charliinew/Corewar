/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** free_struct.c
*/

#include "../../include/corewar.h"

void free_struct(corewar_t *corewar, u_int8_t *memory)
{
    for (int i = 0; i < corewar->nb_champion; i++) {
        if (corewar->champion[i]->flags->prog_name != NULL)
            free(corewar->champion[i]->flags->prog_name);
        if (corewar->champion[i]->header != NULL)
            free(corewar->champion[i]->header);
        free(corewar->champion[i]->flags);
        free(corewar->champion[i]);
    }
    free(corewar);
    free(memory);
}
