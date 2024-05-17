/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** set_champion.c
*/

#include "../../include/corewar.h"

void set_champion_next(corewar_t *corewar)
{
    champion_t *tmp = *corewar->champion;

    for (; tmp != NULL; tmp = tmp->next) {
        tmp->PC = tmp->flags->a;
        tmp->reg[0] = tmp->flags->n;
        for (int j = 1; j < REG_NUMBER; j++)
            tmp->reg[j] = 0;
    }
}

champion_t *set_champion(void)
{
    champion_t *champion = malloc(sizeof(champion_t));

    if (champion == NULL)
        return NULL;
    champion->flags = malloc(sizeof(flags_t));
    champion->header = NULL;
    if (champion->flags == NULL) {
        free(champion);
        return NULL;
    }
    champion->cycle_instruction = 0;
    champion->live = 0;
    champion->last_live = 0;
    champion->carry = 1;
    champion->flags->n = -1;
    champion->flags->a = -1;
    champion->flags->prog_name = NULL;
    champion->next = NULL;
    return champion;
}
