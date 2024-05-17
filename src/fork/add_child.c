/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-charles.ignoux
** File description:
** add_child.c
*/

#include "../../include/corewar.h"

void set_child_next(champion_t **begin, champion_t *tmp)
{
    champion_t *add = *begin;

    if (*begin == NULL) {
        *begin = tmp;
        return;
    }
    for (; add->next != NULL; add = add->next);
    add->next = tmp;
}

void add_child(corewar_t *corewar, champion_t *champion, int child_pc, int
    cycle_instruction)
{
    champion_t *new_champion = malloc(sizeof(champion_t));

    new_champion->id = champion->id;
    new_champion->cycle_instruction = cycle_instruction;
    new_champion->live = 0;
    new_champion->last_live = 0;
    new_champion->PC = child_pc;
    new_champion->carry = champion->carry;
    new_champion->header = copy_header(champion->header);
    new_champion->flags = copy_flags(champion->flags);
    for (int i = 0; i < REG_NUMBER; i++)
        new_champion->reg[i] = champion->reg[i];
    new_champion = set_champion_child(new_champion);
    new_champion->next = NULL;
    set_child_next(champion->child, new_champion);
    return;
}
