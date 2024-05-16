/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_champion.c
*/

#include "../../include/corewar.h"

void set_champion_next(corewar_t *corewar)
{
    for (int i = 0; i < corewar->nb_champion; i++) {
        corewar->champion[i]->PC = corewar->champion[i]->flags->a;
        corewar->champion[i]->reg[0] = corewar->champion[i]->flags->n;
        for (int j = 1; j < REG_NUMBER; j++)
            corewar->champion[i]->reg[j] = 0;
    }
}

champion_t *set_champion(void)
{
    champion_t *champion = malloc(sizeof(champion_t));

    if (champion == NULL)
        return NULL;
    champion->flags = malloc(sizeof(flags_t));
    if (champion->flags == NULL) {
        free(champion);
        return NULL;
    }
    champion->cycle_instruction = 0;
    champion->live = 0;
    champion->carry = 0;
    champion->flags->n = -1;
    champion->flags->a = -1;
    champion->flags->prog_name = NULL;
    return champion;
}
