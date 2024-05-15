/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** check_champion.c
*/

#include "../../include/corewar.h"

int check_champion(corewar_t *corewar)
{
    for (int i = 0; i < 4; i++) {
        if (corewar->champion[i] != NULL) {
            corewar->nb_champion++;
            corewar->champion[i]->id = i + 1;
        } else
            break;
    }
    if (corewar->nb_champion < 2)
        return 84;
    for (int i; i < corewar->nb_champion; i++) {
        if (corewar->champion[i]->flags->prog_name == NULL)
            return 84;
        if (corewar->champion[i]->flags->a >= MEM_SIZE)
            return 84;
    }
    return 0;
}
