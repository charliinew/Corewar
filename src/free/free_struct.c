/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** free_struct.c
*/

#include "../../include/corewar.h"

void free_champ(champion_t *current)
{
    champion_t *next;

    for (; current != NULL; current = next) {
        next = current->next;
        if (current->flags->prog_name != NULL)
            free(current->flags->prog_name);
        free(current->flags);
        free(current->header);
        free(current);
    }
}

void free_struct(corewar_t *corewar, u_int8_t *memory)
{
    free_champ(*corewar->champion);
    free(memory);
}
