/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar_struct.c
*/

#include "../include/corewar.h"

corewar_t *init_corewar_struct(void)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    if (corewar == NULL)
        return NULL;
    corewar->dump = -1;
    corewar->nb_champion = 0;
    for (int i = 0; i < 4; i++) {
        corewar->champion[i] = NULL;
    }
    return corewar;
}
